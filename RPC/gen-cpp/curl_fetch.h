#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/select.h>
#include <curl/curl.h>

struct wd_in {
  size_t size;
  size_t len;
  char *data;
};

/* This function is registered as a callback with CURL.  As the data
   from the requested webpage is returned in chunks, write_data is
   called with each chunk.  */
static size_t write_data(void *buffer, size_t size, 
                         size_t nmemb, wd_in *userp);
int fetch_url(std::string input_url) ;
