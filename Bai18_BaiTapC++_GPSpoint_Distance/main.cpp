#include<iostream>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

#define EARTH_RADIUS 6371
#define PI 3.14159265359

class GPSPoint{
    private:
        double longitude;
        double latitude;
    public:
        void input(double Latitude, double Longitude){
            latitude = Latitude;
            longitude = Longitude;
        }
        bool isValid(double Latitude, double Longitude){
            if(Latitude >= (-90) && Latitude <= 90){
                if(Longitude >= (-180) && Longitude <= 180)
                    return true;
            }
            cerr<<"Invalid, please enter again!"<<endl;
            return false;
        }
        void toRadians(double Latitude, double Longitude){
            latitude = (Latitude * PI) / 180;
            longitude = (Longitude * PI) / 180;
        }
        double distanceTo(double Latitude1, double Longitude1, double Latitude2, double Longitude2){
            return EARTH_RADIUS*2*asin(sqrt(pow(sin(PI/180*(Latitude2-Latitude1)/2),2)+cos(PI/180*Latitude1)*cos(PI/180*Latitude2)*pow(sin(PI/180*(Longitude2-Longitude1)/2),2)));
        }
};

int main(int argc, char **argv){
    double longitude1;
    double latitude1;
    double longitude2;
    double latitude2;
    double distance;

    GPSPoint point;

    cout<<"Enter coordinate of points:"<<endl;
    cout<<"Points 1\n";

    do{
        cout<<"Enter latitude1: ";
        cin>>latitude1;
        cout<<"Enter longitude1: ";
        cin>>longitude1;
    }
    while(point.isValid(latitude1, longitude1) == false);

    cout<<"Points 2\n";

    do{
        cout<<"Enter latitude2: ";
        cin>>latitude2;
        cout<<"Enter longitude2: ";
        cin>>longitude2;
    }
    while(point.isValid(latitude2, longitude2) == false);

    distance = point.distanceTo(latitude1, longitude1, latitude2, longitude2);

    cout<<"Distance of two point is: "<<distance<<" km"<<endl;
    return 0;
}