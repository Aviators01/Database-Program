/*
Timothy Queva
CS2910 Lab1
January 21, 2021

This program will import an xml file into a map and allow the user to
manipulate the database. Afterwards, the updated map will be exported
back to xml file.
*/

#include <boost/algorithm/string.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/map.hpp>

#include <iostream>
#include <sstream>
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

int main(int argc,char** argv){
	string file_name = "Test.xml";
	bool file_rcv = false;
	
	//This reads the XML file into a map
	while(!file_rcv){
		try{
			ifstream ifile;
			ifile.open(file_name);
			{
			boost::archive::xml_iarchive iarch(ifile);
			iarch & BOOST_SERIALIZATION_NVP (orig_map);
			}
			ifile.close();
			
			file_rcv = true;
			cout << endl;
		}
		catch(boost::archive::archive_exception ex){
			cout << "Please provide the XML file you wish to view/change (eg. Test.xml): ";
			cin >> file_name;
			
			if(file_name.find(".xml") == -1) file_name += ".xml";	//Adds the .xml to file name if user forgets to put it in
		}
	}
	
	//Get the schema
	string schema = "";
	if(orig_map.find("ID") != orig_map.end()) schema = orig_map["ID"];
	else if(orig_map.find("Id") != orig_map.end()) schema = orig_map["Id"];
	else if(orig_map.find("iD") != orig_map.end()) schema = orig_map["iD"];
	else if(orig_map.find("id") != orig_map.end()) schema = orig_map["id"];
	else{
		cout << "ERROR: no schema could be found." << endl << endl;
		cout << "In order for this program to work, the schema must be provided correctly." << endl;
		cout << "Please check the XML file and restart this program.";
		exit(-1);
	}
	
	//Instructions for user
	cout << "Commands for database are: add, select, delete, and close. eg.:" << endl;
	cout << "add Manuel,Acosta,67,Reception where ID=6" << endl;
	cout << "select where ID=7 (alt: 'select all' will print entire database')" << endl;
	cout << "delete where ID=8" << endl;
	cout << "close" << endl << endl;
	
	string response = "";
	string internal = "";
	while(internal != "close"){
		cout << "What would you like to do? : ";
		getline(cin,response);
		internal = response;
		
		//Converts response to lowercase
		transform(response.begin(),response.end(),internal.begin(), ::tolower);
		
		//unless there exists a database where a command with keyword (eg. "close") will be at the
		//character position of unsigned int -1, there shouldn't be a problem with this algorithm.
		if(internal.find("add") == 0){
			//Finds id number of record
			auto id_pos = internal.find("id=");
			id_pos +=3;
			string id = internal.substr(id_pos);
			
			cout << "ID is" << id;
			
			if(orig_map.find(id) != orig_map.end()){
				auto attrib_pos = internal.find("add");
				attrib_pos += 4;
				
				string attributes = response.substr(attrib_pos,internal.find(" where"));
				while(attributes.find(",") != -1){
					attributes.replace(attributes.find(","),attributes.find(",")+1, ":");
				}
				
				orig_map[id] = attributes;
				
				cout << "Record <" << id << ">" << attributes << " added to the database." << endl;
			}
			else cout << "Sorry! Record with ID=" << id << " already exists in database." << endl << endl;
			dumpDict(orig_map);
			
		}
		else if(internal.find("select") == 0){
			
			
		}
		else if(internal.find("delete") == 0){
			
			
		}
		else if(internal.find("close") == -1){
			cout << "Sorry! I didn't understand. Please retype your command." << endl << endl;
		}
	}
	
	cout << "Updating XML document database...";
	/*
	//This serializes the updated map as an XML
	ofstream ofile;
	ofile.open("Test.xml");
	{
	boost::archive::xml_oarchive oarch(ofile);
	oarch & BOOST_SERIALIZATION_NVP (orig_map);
	}
	ofile.close();
	
	cout << "Update complete." << endl;
	*/
	return 0;
}