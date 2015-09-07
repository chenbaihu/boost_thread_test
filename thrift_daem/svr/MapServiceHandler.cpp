// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "MapServiceHandler.h"
#include <stdio.h>

MapServiceHandler::MapServiceHandler()
{
    // Your initialization goes here
}


void MapServiceHandler::compute(ComputeResp& _return, const ComputeReq& req) 
{
    fprintf(stdout, 
            "req.cityId=%d\t"
            "creq.oidList.size=%ld\t"
            "creq.didList.size=%ld\n", 
            req.cityId, 
            req.oidList.size(), 
            req.didList.size()); 

    _return.type = OrderType::COMMONORDER;
    _return.data = std::string("hello client");
    return;
}

