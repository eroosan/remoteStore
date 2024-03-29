/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef RemoteOperations_H
#define RemoteOperations_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "RemoteOperations_types.h"

namespace RemoteOperations { namespace thrift { namespace impl {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class RemoteOperationsIf {
 public:
  virtual ~RemoteOperationsIf() {}
  virtual void connect(std::string& _return) = 0;
  virtual bool insertUser(const UserData& userData) = 0;
};

class RemoteOperationsIfFactory {
 public:
  typedef RemoteOperationsIf Handler;

  virtual ~RemoteOperationsIfFactory() {}

  virtual RemoteOperationsIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(RemoteOperationsIf* /* handler */) = 0;
};

class RemoteOperationsIfSingletonFactory : virtual public RemoteOperationsIfFactory {
 public:
  RemoteOperationsIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<RemoteOperationsIf>& iface) : iface_(iface) {}
  virtual ~RemoteOperationsIfSingletonFactory() {}

  virtual RemoteOperationsIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(RemoteOperationsIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<RemoteOperationsIf> iface_;
};

class RemoteOperationsNull : virtual public RemoteOperationsIf {
 public:
  virtual ~RemoteOperationsNull() {}
  void connect(std::string& /* _return */) {
    return;
  }
  bool insertUser(const UserData& /* userData */) {
    bool _return = false;
    return _return;
  }
};


class RemoteOperations_connect_args {
 public:

  RemoteOperations_connect_args(const RemoteOperations_connect_args&);
  RemoteOperations_connect_args& operator=(const RemoteOperations_connect_args&);
  RemoteOperations_connect_args() {
  }

  virtual ~RemoteOperations_connect_args() throw();

  bool operator == (const RemoteOperations_connect_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const RemoteOperations_connect_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RemoteOperations_connect_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RemoteOperations_connect_pargs {
 public:


  virtual ~RemoteOperations_connect_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RemoteOperations_connect_result__isset {
  _RemoteOperations_connect_result__isset() : success(false) {}
  bool success :1;
} _RemoteOperations_connect_result__isset;

class RemoteOperations_connect_result {
 public:

  RemoteOperations_connect_result(const RemoteOperations_connect_result&);
  RemoteOperations_connect_result& operator=(const RemoteOperations_connect_result&);
  RemoteOperations_connect_result() : success() {
  }

  virtual ~RemoteOperations_connect_result() throw();
  std::string success;

  _RemoteOperations_connect_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const RemoteOperations_connect_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RemoteOperations_connect_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RemoteOperations_connect_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RemoteOperations_connect_presult__isset {
  _RemoteOperations_connect_presult__isset() : success(false) {}
  bool success :1;
} _RemoteOperations_connect_presult__isset;

class RemoteOperations_connect_presult {
 public:


  virtual ~RemoteOperations_connect_presult() throw();
  std::string* success;

  _RemoteOperations_connect_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _RemoteOperations_insertUser_args__isset {
  _RemoteOperations_insertUser_args__isset() : userData(false) {}
  bool userData :1;
} _RemoteOperations_insertUser_args__isset;

class RemoteOperations_insertUser_args {
 public:

  RemoteOperations_insertUser_args(const RemoteOperations_insertUser_args&);
  RemoteOperations_insertUser_args& operator=(const RemoteOperations_insertUser_args&);
  RemoteOperations_insertUser_args() {
  }

  virtual ~RemoteOperations_insertUser_args() throw();
  UserData userData;

  _RemoteOperations_insertUser_args__isset __isset;

  void __set_userData(const UserData& val);

  bool operator == (const RemoteOperations_insertUser_args & rhs) const
  {
    if (!(userData == rhs.userData))
      return false;
    return true;
  }
  bool operator != (const RemoteOperations_insertUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RemoteOperations_insertUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RemoteOperations_insertUser_pargs {
 public:


  virtual ~RemoteOperations_insertUser_pargs() throw();
  const UserData* userData;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RemoteOperations_insertUser_result__isset {
  _RemoteOperations_insertUser_result__isset() : success(false) {}
  bool success :1;
} _RemoteOperations_insertUser_result__isset;

class RemoteOperations_insertUser_result {
 public:

  RemoteOperations_insertUser_result(const RemoteOperations_insertUser_result&);
  RemoteOperations_insertUser_result& operator=(const RemoteOperations_insertUser_result&);
  RemoteOperations_insertUser_result() : success(0) {
  }

  virtual ~RemoteOperations_insertUser_result() throw();
  bool success;

  _RemoteOperations_insertUser_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const RemoteOperations_insertUser_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RemoteOperations_insertUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RemoteOperations_insertUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RemoteOperations_insertUser_presult__isset {
  _RemoteOperations_insertUser_presult__isset() : success(false) {}
  bool success :1;
} _RemoteOperations_insertUser_presult__isset;

class RemoteOperations_insertUser_presult {
 public:


  virtual ~RemoteOperations_insertUser_presult() throw();
  bool* success;

  _RemoteOperations_insertUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RemoteOperationsClient : virtual public RemoteOperationsIf {
 public:
  RemoteOperationsClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  RemoteOperationsClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void connect(std::string& _return);
  void send_connect();
  void recv_connect(std::string& _return);
  bool insertUser(const UserData& userData);
  void send_insertUser(const UserData& userData);
  bool recv_insertUser();
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class RemoteOperationsProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<RemoteOperationsIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (RemoteOperationsProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_connect(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_insertUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RemoteOperationsProcessor(::apache::thrift::stdcxx::shared_ptr<RemoteOperationsIf> iface) :
    iface_(iface) {
    processMap_["connect"] = &RemoteOperationsProcessor::process_connect;
    processMap_["insertUser"] = &RemoteOperationsProcessor::process_insertUser;
  }

  virtual ~RemoteOperationsProcessor() {}
};

class RemoteOperationsProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  RemoteOperationsProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< RemoteOperationsIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< RemoteOperationsIfFactory > handlerFactory_;
};

class RemoteOperationsMultiface : virtual public RemoteOperationsIf {
 public:
  RemoteOperationsMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<RemoteOperationsIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~RemoteOperationsMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<RemoteOperationsIf> > ifaces_;
  RemoteOperationsMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<RemoteOperationsIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void connect(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->connect(_return);
    }
    ifaces_[i]->connect(_return);
    return;
  }

  bool insertUser(const UserData& userData) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->insertUser(userData);
    }
    return ifaces_[i]->insertUser(userData);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class RemoteOperationsConcurrentClient : virtual public RemoteOperationsIf {
 public:
  RemoteOperationsConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  RemoteOperationsConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void connect(std::string& _return);
  int32_t send_connect();
  void recv_connect(std::string& _return, const int32_t seqid);
  bool insertUser(const UserData& userData);
  int32_t send_insertUser(const UserData& userData);
  bool recv_insertUser(const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}}} // namespace

#endif
