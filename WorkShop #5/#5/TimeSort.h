#ifndef TIME_SORT_H_
#define TIME_SORT_H_

#include <iostream>
#include <cstdlib> // for qsort
using namespace std;

int compareTime(const void* a, const void* b);

class Time {

      public:

         Time(); // constructor
         Time(int h1, int m1, int s1):hour(h1), minute(m1), second(s1){};
         ~Time(){}; //deconstructor
         void setTime( int, int, int ); // set hour, minute, second
         void printTime() const {
        	 std::cout<< hour <<"\t"<< minute <<"\t"<< second<<std::endl;// print time format h:m:s
         }

         int getHour(){return hour;};
         int getMinute(){return minute;};
         int getSecond(){return second;};

         friend int compareTime(const void* a, const void* b); //not a memberfunction;

//       friend ostream& operator<<(ostream& out, const Time &t){
//
//         	 	out << t.hour << " : " << t.minute << " : " << t.second;
//         	 	return out;
//
//
//         };
//
//         friend istream& operator>>(istream& in, Time& t){
//         	 cout << "please input the hour"<< endl;
//         	 in >> t.hour;
//
//         	 cout << "please input the minute"<< endl;
//         	 in >> t.minute;
//
//         	 cout << "please input the second"<< endl;
//         	 in >> t.second;
//
//         	 return in;
//
//
//         };


      private:
       int hour;     // 0 - 23 (24-hour clock format)
       int minute;   // 0 - 59
       int second;   // 0 - 59
       static int counter;

};



int compareTime(const void* a, const void* b) {
    const Time* time1 = static_cast<const Time*>(a);
    const Time* time2 = static_cast<const Time*>(b);

    if (time1->hour != time2->hour) {
        return time1->hour - time2->hour;
    } else if (time1->minute != time2->minute) {
        return time1->minute - time2->minute;

    } else {
        return time1->second - time2->second;

    }
}

// Unit test function
void testSortingTimeObjects() {
	//test case with test data;

    Time times[] = {
        Time(14, 30, 45),
        Time(9, 15, 20),
        Time(21, 5, 10),
        Time(14, 30, 30),
        Time(0, 0, 0)
    };

    size_t size = sizeof(times) / sizeof(times[0]);

    cout << "Before sorting:" << endl;
    for (size_t i = 0; i < size; ++i) {
        times[i].printTime();
        cout << endl;
    }

    // Sort using qsort
    qsort(times, size, sizeof(Time), compareTime);

    cout << "After sorting:" << endl;
    for (size_t i = 0; i < size; ++i) {
        times[i].printTime();
        cout << endl;
    }

//    Time t;
//    t.compareTime(); // wrong invocation, no need for object;
//    compareTime();
}

#endif /* TIME_SORT_H_ */
