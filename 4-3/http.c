#include "http.h"
#include <stdio.h>

char *http_to_str(HttpErrorCode code) {
	char* status_code;
	switch (code) {
		case HTTP_BAD_REQUEST:
			status_code = "400 Bad Request";
			break;
		case HTTP_UNAUTHORIZED:
			status_code = "401 Unauthorized";
			break;
		case HTTP_NOT_FOUND:
			status_code = "404 Not Found";
			break;
		case HTTP_TEAPOT:
			status_code = "418 I AM A TEAPOT!";
			break;
		case HTTP_INTERNAL_SERVER_ERROR:
			status_code = "500 Internal Server Error";
			break;
		default:
			status_code = "Unknown HTTP status code";
			break;
	}
	return status_code;
}
