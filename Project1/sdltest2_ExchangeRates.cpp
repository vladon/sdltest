#include "sdltest2.h"
#include "CValuteEntry.h"
#include <SDL.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <curl/curl.h>
#include <curl/easy.h>
#include <tinyxml2.h>

#define MAX_FILE_SIZE 10485760 //10 MiB

size_t curl_to_string(void *ptr, size_t size, size_t count, void *stream)
{
	if (((std::string*)stream)->size() + (size * count) > MAX_FILE_SIZE)
	{
		return 0;
	}
	int retry = 0;
	while (true)
	{
		try{
			((std::string*)stream)->append((char*)ptr, 0, size*count);
			break;// successful
		}
		catch (const std::bad_alloc&) {
			retry++;
			if (retry>100)
			{
				return 0;
			}
			Sleep(10);
		}
	}
	return size*count;
}

void SDLTest2::LoadExchangeRates()
{
#ifdef DEBUG
	std::cout << "Entered LoadExchangeRates" << std::endl;
#endif

	std::string url = "http://www.cbr.ru/scripts/XML_daily.asp?date_req=";

	// get current date for url
	std::time_t t = std::time(nullptr);
	std::tm current_tm;
	char mbstr[11]; // DD.MM.YYYY

	errno_t err = localtime_s(&current_tm, &t);
	if (!err)
	{
		if (std::strftime(mbstr, sizeof(mbstr), "%d.%m.%Y", &current_tm))
		{
			url.append(mbstr);

			// download url to buffer

			CURL *curl;
			CURLcode res;
			std::string readBuffer;

			curl = curl_easy_init();
			if (curl)
			{
				curl_easy_setopt(curl, CURLOPT_URL, url);
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_to_string);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
				res = curl_easy_perform(curl);
				curl_easy_cleanup(curl);
			}

			// parse xml
			tinyxml2::XMLDocument doc;

			/*
			XML:

			<ValCurs>
			<Valute ID="xxxx">
			<Valute ID="R01010">
			<NumCode>036</NumCode>
			<CharCode>AUD</CharCode>
			<Nominal>1</Nominal>
			<Name>Австралийский доллар</Name>
			<Value>51,3999</Value>
			</Valute>
			...
			</ValCurs>
			*/

			doc.Parse(readBuffer.c_str());

			tinyxml2::XMLNode* xRoot = doc.RootElement();

			if (xRoot == nullptr)
			{
				// ERROR	
				// std::cout << "Error parsing XML" << std::endl;
			}
			else
			{
				// traverse

				const int spaceX = 16;
				const int spaceY = 3;

				int iX = 0;
				int iY = 0;

				SDL_Color blackColor = { 0, 0, 0 };

				for (tinyxml2::XMLElement* iElement = xRoot->FirstChildElement("Valute"); iElement != nullptr; iElement = iElement->NextSiblingElement())
				{
					std::string iNominal = iElement->FirstChildElement("Nominal")->GetText();
					std::string iCharCode = iElement->FirstChildElement("CharCode")->GetText();
					std::string iValue = iElement->FirstChildElement("Value")->GetText();

					iY += spaceY;

					CValuteEntry* iValuteEntry = new CValuteEntry(iNominal, iCharCode, iValue);
					ValuteEntries.push_back(iValuteEntry);
				}
			}
		}
	}
}

void SDLTest2::PostExchangeRates() {
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, POST_URL);
		curl_easy_setopt(curl, CURLOPT_POST, 1);

		std::string postfields;

		for (auto &i : ValuteEntries) {
			postfields = "charcode=" + i->CharCode + "&nominal=" + i->Nominal + "&value=" + i->Value;
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postfields);

			res = curl_easy_perform(curl);
		}

		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();
}