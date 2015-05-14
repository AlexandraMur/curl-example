#include <stdio.h>
#include "curl/curl.h"
#include <string>

int main(void) {
	CURL *curl;
	FILE *fp;
	CURLcode res;

	//char *url = "http://wc.exn.su:8888/attachments/download/3/OfForestAndMen.zip";
	char *url = "http://curl.haxx.se/download/curl-7.20.0.tar.gz";
	char outfilename[FILENAME_MAX] = "DownloadFile.tar.gz";
	curl = curl_easy_init();
	if (curl) {
		fp = fopen(outfilename,"wb");
        	curl_easy_setopt(curl, CURLOPT_URL, url);
        	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        	res = curl_easy_perform(curl);
        	curl_easy_cleanup(curl);
        	fclose(fp);
    	}
	return 0;
}
