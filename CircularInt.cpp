#include "CircularInt.hpp"

CircularInt::CircularInt(int a, int b){ //constructor
	if(a > b)
	{
		this->big = a;
		this->small = b;
	}
	else
	{
		this->small = a;
		this->big = b;
	}
	this->now = this->small;
}

CircularInt::CircularInt(const CircularInt& h){ //copy constructor

	this->small = h.small;
	this->big = h.big;
	this->now = h.now;
}

CircularInt& CircularInt::operator/=(const int num){
	*this= *this/num;
		return *this;
}

CircularInt& CircularInt::operator/=(const CircularInt& h){
	*this= *this/h.now;
	return *this;
}

CircularInt& CircularInt::operator-=(const int num){
	this->now = this->now - num;
	if(this->now < small)
	{
		this->now = this->now % big + big;
	}
	return *this;
}

CircularInt& CircularInt::operator-=(const CircularInt& h){
	this->now = this->now - h.now;
	if(this->now < small)
	{
		this->now = this->now % big + big;
	}
	return *this;
}

CircularInt& CircularInt::operator+=(const int num) {
	this->now = this->now+num;
	if(this->now >big)
	{
		this->now = this->now % big;
	}
	return *this;
}

CircularInt& CircularInt::operator+=(const CircularInt& h) {
	this->now = this->now+h.now;
	if(this->now > big)
	{
		this->now = this->now % big;
	}
	return *this;
}

CircularInt CircularInt::operator--(int){
	CircularInt temp(*this);
	operator--();
	return temp;
}

CircularInt& CircularInt::operator--(){
	now--;
	while(now<small){
		now=now+big;
	}
	return *this;
}

CircularInt CircularInt::operator++(int){
	CircularInt temp(*this);
	operator++();
	return temp;
}

CircularInt& CircularInt::operator++(){
	now++;
	if(now > big)
	{
		now =now %big;
	}
	return *this;
}

CircularInt& CircularInt::operator*=(const int num){
	now*=num;

	while(now >big)
	{
		now-=big;
	}
	while(now < small)
	{
		now+=big;
	}

	return *this;
}

CircularInt& CircularInt::operator*=(const CircularInt& h){
	now*=h.now;

	while(now >big)
	{
		now-=big;
	}
	while(now < small)
	{
		now+=big;
	}

	return *this;
}

CircularInt& CircularInt::operator=(const CircularInt& h){
	now = h.now;
	if(now > big)
	{
		now =now % big;
	}
	while(now<small){
		now+=big;
	}
	return *this;

}

CircularInt& CircularInt::operator=(const int num){

	now = num;
	if(now > big)
	{
		now =now %big;
	}
	while(now<small){
		now+=big;
	}
	return *this;
}
