/*
Timothy Queva
CS2910 Lab1
January 25, 2021

In this program, we are using boost to import a csv file and turn it into
an xml file through a map. Code was taken from assignment page-written by
Franco Carlacci. Adapted by Timothy Queva.
*/

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/map.hpp>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> REC;
typedef map<string,string> DB;

REC strs;
string line;
DB orig_map;

void dumpDict(DB d){
	for(auto &e :d){
		cout << e.first;
		cout << "<" << e.second << ">" ;
		cout << endl;
	}
}

int main(){
	cout << "If you just see a blinking cursor, this means you forgot to give a file to this program." << endl;
	cout << "Press ctrl + d or ctrl + c to end program and then type: ./part1 < Test.csv\n" << endl;
	
	cout << "This is what will be converted to an xml file format:" << endl;
	
    while(getline(cin,line)){
		boost::split(strs,line,boost::is_any_of(",;"));
		
		for(auto i : strs){
			cout << setw(12) << left << i;
		}
		cout << endl;
		
		//add a record ( aka line) to database
		orig_map[strs[0]] = boost::algorithm::join(strs, ":");
    }
	
	cout << endl << endl;
	//serializes map as an XML document
	dumpDict(orig_map);   
	ofstream ofile;
	ofile.open("Test.xml");
	{
	boost::archive::xml_oarchive oarch(ofile);
	oarch & BOOST_SERIALIZATION_NVP (orig_map);
	}
	ofile.close();
	
	return 0;
}