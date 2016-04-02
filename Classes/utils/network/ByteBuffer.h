#ifndef BYTE_BUFFER_H
#define BYTE_BUFFER_H

#include "Util.h"

int readIntFromBuffer(char* buffer,int position);

class ByteBuffer
{
public:
	ByteBuffer(int capacity);
	ByteBuffer(char* data,int offset,int capacity);
	~ByteBuffer();
	
	void putBool(bool b);
	void putByte(byte b);
	void putShort(short n);
	void putFloat(float n);
	void putInt(int n);
	void putLong(long long n);
	void putUTF(const char* str);
	void putUTF(const String& str);
	void putArray(vector<byte>& a);
	void putArray(vector<bool>& a);
	void putArray(vector<short>& a);
	void putArray(vector<int>& a);
	void putArray(vector<long long>& a);
	void putArray(vector<string>& a);
    void put(const char* bytes,int offset,int len);
    
    
    String getUTF();
    char* getBuffer();
    byte getByte();
    bool getBool();
    int getInt();
    float getFloat();
    short getShort();
	void getArray(vector<byte>& a);
	void getArray(vector<bool>& a);
	void getArray(vector<short>& a);
	void getArray(vector<int>& a);
	void getArray(vector<long long>& a);
	void getArray(vector<string>& a);
	void getArray(vector<byte>& a,int len);
	void getArray(vector<bool>& a,int len);
	void getArray(vector<short>& a,int len);
	void getArray(vector<int>& a,int len);
	void getArray(vector<long long>& a,int len);
	void getArray(vector<string>& a,int len);
    void get(char* bytes,int size);
    void get(char* bytes,int offset,int len);
	void getUTF(String& str);
    
    
    void setIntAt(int n,int index);
    
	//这个方法只能用于打开的是文本文件的时候
	String getLine();
	
	long long getLong();
	
    /**
     * limit - position
     */
    int remaining();
    
    int getPosition();
    void setPosition(int p);
    int getCapacity();
    int getLimit();
    
	/**
	 * makes a buffer ready for a new sequence of channel-read or relative put operations: It sets the limit to the capacity and the position to zero.
	 */
    void clear();
    
    int getLength(int offset);
    void getAsBytes(byte* bytes);
	
    /**
    * makes a buffer ready for a new sequence of channel-write or relative get operations: It sets the limit to the current position and then sets the position to zero.
    */
    void flip();
    
    void compact();
    void rewind();
    
private:
    char* buffer;
    
    int position;
    int capacity;
    int limit;
};


#endif
