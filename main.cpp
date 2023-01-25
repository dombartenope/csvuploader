#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//Create an instance of a user
struct User {
    string app_id;
    int device_id;
    string identifier;
    string identifier_auth_hash;
    string test_type;
    string language;
    string external_user_id;
    string external_user_id_auth_hash;
    string timezone;
    string game_version;
    string device_model;
    string device_os;
    int session_count;
    double amount_spent;
    int created_at;
    int playtime;
    int last_active;
    int notification_types;
    double lat;
    double lon;
    string country;
    string timezone_id;
    vector<pair<string,string>> tags;
};

#define PRINT_MEMBERS(a) \
    cout << #a << ": " << a << endl;

void printUser(User user) {
    PRINT_MEMBERS(user.app_id);
    PRINT_MEMBERS(user.device_id);
    PRINT_MEMBERS(user.identifier);
    PRINT_MEMBERS(user.identifier_auth_hash);
    PRINT_MEMBERS(user.test_type);
    PRINT_MEMBERS(user.language);
    PRINT_MEMBERS(user.external_user_id);
    PRINT_MEMBERS(user.external_user_id_auth_hash);
    PRINT_MEMBERS(user.timezone);
    PRINT_MEMBERS(user.game_version);
    PRINT_MEMBERS(user.device_model);
    PRINT_MEMBERS(user.device_os);
    PRINT_MEMBERS(user.session_count);
    PRINT_MEMBERS(user.amount_spent);
    PRINT_MEMBERS(user.created_at);
    PRINT_MEMBERS(user.playtime);
    PRINT_MEMBERS(user.last_active);
    PRINT_MEMBERS(user.notification_types);
    PRINT_MEMBERS(user.lat);
    PRINT_MEMBERS(user.lon);
    PRINT_MEMBERS(user.country);
    PRINT_MEMBERS(user.timezone_id);
    for(auto &[key, value] : user.tags) {
        cout << "user.tags : " << key << "," << value << endl;
    }
    
}

void makeCurlRequest(User &user){
    printUser(user);
}

int main() {
    //open the csv in directory named "input"
    ifstream input("input.csv");
    //Throw error if unable to open
    if(!input.is_open()) {
        cout << "Sorry, unable to open file please try again" << endl;
    } 

    //Define line of csv that is going to be read
    string line;

    //ignore the column names in the first line when making the request
    input.ignore(numeric_limits<streamsize>::max(),'\n');
    
    //While there are lines in the csv
    while(getline(input, line)){

        //create a stringstream object from the line
        stringstream ss(line);

        //Define a new user
        User user;
        
        //Change the properties of the user by assigning from the csv
        getline(ss, user.app_id, ',');
        //Declare string for device_id
        string device_id;
        //We need to pull the value out as a string and change cast to int
        getline(ss, device_id, ',');
        //We check for empty string, and if not, use strint to int method
        if(!device_id.empty()) {   
            user.device_id = stoi(device_id);
        } else {
            user.device_id = 0;
        }

        getline(ss, user.identifier, ',');
        getline(ss, user.identifier_auth_hash, ',');
        getline(ss, user.test_type, ',');
        getline(ss, user.language, ',');
        getline(ss, user.external_user_id, ',');
        getline(ss, user.external_user_id_auth_hash, ',');
        getline(ss, user.timezone, ',');
        getline(ss, user.game_version, ',');
        getline(ss, user.device_model, ',');
        getline(ss, user.device_os, ',');

        string session_count;
        getline(ss, session_count, ',');
        if(!session_count.empty()) {
            user.session_count = stoi(session_count);
        }

        string amount_spent;
        getline(ss, amount_spent, ',');
        if(!amount_spent.empty()) {
            user.amount_spent = stod(amount_spent);
        }

        string created_at;
        getline(ss, created_at, ',');
        if(!created_at.empty()){
            user.created_at = stoi(created_at);
        }

        string playtime;
        getline(ss, playtime, ',');
        if(!playtime.empty()) {
            user.playtime = stoi(playtime);
        }

        string last_active;
        getline(ss, last_active, ',');
        if(!last_active.empty()) {
            user.last_active = stoi(last_active);
        }

        string notification_types;
        getline(ss, notification_types, ',');
        if(!notification_types.empty()) {
            user.notification_types = stoi(notification_types);
        }

        string lat;
        getline(ss, lat, ',');
        if(!lat.empty()) {
            user.lat = stod(lat);
        }
        string lon;
        getline(ss, lon, ',');
        if(!lon.empty()) {
            user.lon = stod(lon);
        }

        getline(ss, user.country, ',');
        getline(ss, user.timezone_id, ',');

        //Allow multiple tags to be uploaded for each user that is going to be created.
        string tagsLine;
        getline(ss, tagsLine);
        stringstream tagss(tagsLine);
        string tag;
        while(getline(tagss, tag, ',')) {
            string key, value;
            stringstream tagstream(tag);
            getline(tagstream, key, ':');
            getline(tagstream, value, ':');
            user.tags.push_back(make_pair(key, value));
        }

        


        //TODO loop through user properties and put anything with a value into the curl request
        makeCurlRequest(user);

    } 
    input.close();

    return 0;

}

