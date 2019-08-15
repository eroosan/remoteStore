namespace cpp RemoteOperations.thrift.impl

struct UserData {
    1: i8 userId,
    2: string userName
}

service RemoteOperations {
	string connect(),
	bool insertUser(1:UserData userData)
}




