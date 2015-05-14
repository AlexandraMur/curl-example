#include <stdio.h>
#include "curl/curl.h"
#include <string>
using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    	return fwrite (ptr, size, nmemb, stream)
}

int main(void) {
	CURL *curl;
	FILE *fp;
	CURLcode res;

	char url = "http://wc.exn.su:8888/attachments/download/3/OfForestAndMen.zip";
	//char *url = "http://curl.haxx.se/download/curl-7.20.0.tar.gz";
	char outfilename[FILENAME_MAX] = "DownloadedFile.zip";
	curl = curl_easy_init();
	if (curl) {
		fp = fopen(outfilename,"wb");
        	curl_easy_setopt(curl, CURLOPT_URL, url);
        	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        	res = curl_easy_perform(curl);
        	curl_easy_cleanup(curl);
        	fclose(fp);
    	}
	return 0;
}
