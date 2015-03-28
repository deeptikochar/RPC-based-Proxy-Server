#!/usr/local/bin/thrift

namespace cpp proxyspace

struct response
{
	1:string document,
	2:i32 response_code
}

service HTTPproxy
{
	/* Request document from proxy server */
	response request(1:string url)

	/* Stop the server */
	oneway void shutdown()
}
