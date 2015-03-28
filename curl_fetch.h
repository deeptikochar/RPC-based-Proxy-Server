#ifndef curl_fetch_H
#define curl_fetch_H

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/select.h>
#include <curl/curl.h>
#include "wd_in.h"
/* This function is registered as a callback with CURL.  As the data
   from the requested webpage is returned in chunks, write_data is
   called with each chunk.  */
static size_t write_data(void *buffer, size_t size, 
                         size_t nmemb, wd_in *userp);
int fetch_url(std::string input_url, wd_in &curl_return) ;

#endif