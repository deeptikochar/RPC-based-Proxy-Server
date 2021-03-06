/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "HTTPproxy_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace proxyspace {


response::~response() throw() {
}


void response::__set_document(const std::string& val) {
  this->document = val;
}

void response::__set_response_code(const int32_t val) {
  this->response_code = val;
}

const char* response::ascii_fingerprint = "EEBC915CE44901401D881E6091423036";
const uint8_t response::binary_fingerprint[16] = {0xEE,0xBC,0x91,0x5C,0xE4,0x49,0x01,0x40,0x1D,0x88,0x1E,0x60,0x91,0x42,0x30,0x36};

uint32_t response::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->document);
          this->__isset.document = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->response_code);
          this->__isset.response_code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t response::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("response");

  xfer += oprot->writeFieldBegin("document", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->document);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("response_code", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->response_code);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(response &a, response &b) {
  using ::std::swap;
  swap(a.document, b.document);
  swap(a.response_code, b.response_code);
  swap(a.__isset, b.__isset);
}

response::response(const response& other0) {
  document = other0.document;
  response_code = other0.response_code;
  __isset = other0.__isset;
}
response& response::operator=(const response& other1) {
  document = other1.document;
  response_code = other1.response_code;
  __isset = other1.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const response& obj) {
  using apache::thrift::to_string;
  out << "response(";
  out << "document=" << to_string(obj.document);
  out << ", " << "response_code=" << to_string(obj.response_code);
  out << ")";
  return out;
}

} // namespace
