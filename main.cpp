#include <iostream>

#include <cmath>
//modified code
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

#include <algorithm>
#include <numeric> //lcm, gcd
#include <functional> //plus , greater

#include <set>

#include <chrono>
#include <map>

#include <fstream>

#include <optional>
#include <variant>
#include <any>

#include <memory>
#include <future>
#include <thread>
#include <mutex>

std::mutex mtx;
std::mutex coutMtx;

using namespace std;

optional<string> findUser(int);

void safePrintingStr(const string& msg)
{
    lock_guard<mutex> lock(coutMtx);
    cout<<msg<<endl;
}

int task1(int c);

int heavyCounter = 0;

int heavyWork(int x)
{
    this_thread::sleep_for(chrono::seconds(5));
    return x*x;
}

void printFunc();
int printFunc2();

struct foo
{
  
    int k = 9999;
    foo()
    {
        cout<<"foo constructor created"<<endl;
    }

    ~foo()
    {
        cout<<"foo destructor called"<<endl;
    }
};

struct sharing
{
    int k = 107;
    sharing()
    {
        cout<<"sharing constructor created"<<endl;
    }

    ~sharing()
    {
        cout<<"sharing destructor called"<<endl;
    }
};

void normalFunc(int x,string name)
{
    cout<<name<<x<<" :age"<<endl;
}


struct Counter
{
    int count = 0;
    void operator() (int x)
    {
        if(x%2 == 0) count++;
    }
};

struct square1
{
    int operator() (int x)
    {
        return x*x;
    }
};

namespace zubair
{
    void print()
    {
        cout<<"Print zubair"<<endl;
    }

    int square(int num)
    {
       return num*num;
    }
}


void printVector(vector<int> v)
{
    cout<<endl<<"Vector ( ";
    for(int val : v)
    {
        cout<<val<<" ";
    }
    cout<<")"<<endl;
}

void printDeque(deque<int> v)
{
    cout<<endl<<"deque ( ";
    for(int val : v)
    {
        cout<<val<<" ";
    }
    cout<<")"<<endl;
}

void printVectorRef(const vector<int> &v)
{

    cout<<endl<<"Vector ( ";
    for(int val : v)
    {
        cout<<val<<" ";
    }
    cout<<")"<<endl;
}

void addNumber(vector<int> &v, int num)
{
    v.push_back(num);
    cout<<endl<<"Vector ( ";
    for(int val : v)
    {
        cout<<val<<" ";
    }
    cout<<")"<<endl;
}

int main()
{
    vector<int> primes = {2,3,5,7,11,13,17,19};

    for(int num : primes)
    {
        cout<<num<<" ";
    }

    cout<<endl;
    cout<<primes.capacity()<<endl;

    primes.push_back(23);
    primes.push_back(27);

    for(int num : primes)
    {
        cout<<num<<" ";
    }

    cout<<endl;
    cout<<primes.capacity()<<endl;

    cout<<primes.at(2)<<" :index 2 position"<<endl;
    cout<<primes[2]<<" :index 2 position"<<endl;

    primes.pop_back();

    for(int num : primes)
    {
        cout<<num<<" ";
    }

    cout<<endl;

    primes.insert(primes.begin()+1,100);

    for(int num : primes)
    {
        cout<<num<<" ";
    }
    cout<<endl;

    primes.erase(primes.begin()+1);
    for(int num : primes)
    {
        cout<<num<<" ";
    }
    cout<<endl;

    primes.clear();

    if(primes.empty())
    {
        cout<<"Yup primes are empty now !!!"<<endl;
    }


    vector<string> countries(5,"India");

    for(auto it = countries.begin(); it != countries.end(); it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;
    cout<<countries.size()<<" :countries size";

    vector<float> values = {3.14, 6.26, 8.12, 77.9};

    values.erase(values.end() - 2);

    cout<<endl;
    for(auto val : values)
    {
        cout<<val<<" ";
    }

    cout<<endl;


    vector<int> odds = {1,3,5,7,9};
    printVector(odds);
    printVectorRef(odds);

    addNumber(odds,11);

    vector<int> numbers = {4,9,1,6,2,8};

    sort(numbers.begin(),numbers.end());
    printVectorRef(numbers);

    sort(numbers.rbegin(),numbers.rend());
    printVectorRef(numbers);

    numbers.erase(remove_if(numbers.begin(),numbers.end(),
                            [](int x){return x%2 == 0;}),numbers.end());

    printVector(numbers);

    //Creating a 2D vector

    vector< vector<int> > matrix;

    matrix = {{1,2,3},{3,4,5},{5,6,7}};

    for(const auto &row : matrix)
    {
        for(int val : row)
        {
            cout<<val<<" ";
        }
        // OR
        printVectorRef(row);
    }

    // vector< vector<int> > UnitMatrix;

    // for(int i=0; i<3; i++)
    // {
    //     UnitMatrix.push_back({0,0,0});
    // }

    //OR

    vector< vector<int> > UnitMatrix(3,vector<int>(3,0));


    for(int i=0; i<3; i++)
    {
        UnitMatrix[i][i] = 1;
    }

    for(const auto &row : UnitMatrix)
    {
        printVectorRef(row);
    }

    // 1. Identity matrix

    int n = 4;
    vector< vector<int> > identityMatrix(n,vector<int>(4,0));
    cout<<"IDENTITY MATRIX";

    for(int i=0; i<n; i++)
    {
        identityMatrix[i][i] = 1;
    }

    for(const auto &row : identityMatrix)
    {
        printVectorRef(row);
    }


    // 2. Sum Of All Rows

    cout<<"Sum Of All Rows"<<endl;
    vector< vector<int> > sumOfAllRows(3,vector<int>(3,0));

    int k=1;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            sumOfAllRows[i][j] = k;
            k++;
        }
    }

    for(const auto &row : sumOfAllRows)
    {
        printVectorRef(row);
    }

    vector<int> opSum;
    int sum = 0;
    for(const auto &row : sumOfAllRows)
    {
        for(int val : row)
        {
            sum+=val;
        }

        opSum.push_back(sum);
        sum = 0;
    }

    printVectorRef(opSum);

    // 3. Transpose Of Matrix
    cout<<"Transpose Of MAtrix"<<endl;

    vector< vector<int> > transposeMat = {{1,2,3},{4,5,6}};

    vector< vector<int> > OpTransposeMat(3,vector<int>(2,0));

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
           OpTransposeMat[j][i] = transposeMat[i][j];
        }
    }

    for(const auto &row : OpTransposeMat)
    {
        printVectorRef(row);
    }

    // 4. Print Boundary Elements
    cout<<"Print Boundary Elements"<<endl;
    vector< vector<int> > boundary = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> opBoundary;

    vector<int> revVector;

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i==0)
                opBoundary.push_back(boundary[i][j]);
            else if(j==2 && i==1)
                opBoundary.push_back(boundary[i][j]);
            else if(i==2)
            {
                revVector.push_back(boundary[i][j]);
            }
        }
    }

    reverse(revVector.begin(),revVector.end());
    for(int v : revVector)
    {
        opBoundary.push_back(v);
    }

    opBoundary.push_back(boundary[1][0]);

    printVector(opBoundary);

    // 5.Max Number in row
    cout<<"Max Number in row"<<endl;
    vector< vector<int> > maxMatrix = {{4,2,7},{9,5,1},{6,8,3}};
    vector<int> opMaxMatrix;

    int op = 0;
    for(auto &row : maxMatrix)
    {
        sort(row.rbegin(),row.rend());
        op = row[0];
        opMaxMatrix.push_back(op);
    }

    printVector(opMaxMatrix);


    //std::deque
    deque<int> evens(5,0);
    printDeque(evens);

    evens.push_front(1);
    evens.push_front(2);
    evens.push_back(7);

    printDeque(evens);

    cout<<evens.front()<<" :even front"<<endl;
    evens.pop_front();
    printDeque(evens);


    //std::list
    list<int> l1 = {3,4,5};
    l1.push_front(1);
    l1.push_back(6);

    for(int val : l1)
    {
        cout<<val<<"*";
    }

    cout<<endl;

    //std::forward_list (no end,rend,... only front)
    forward_list<int> f1 = {2,3,4,9,7,7,3,7};

    forward_list<int> f2 = {3,3,98,76,3456};
    f1.insert_after(f1.begin(),100);

    f1.remove(4);

    f1.unique();

    f1.merge(f2);

    for(int val : f1)
    {
        cout<<val<<"*";
    }

    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,6};
    vector<int> res(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),res.begin());

    printVector(res);


    // std::array

    array<int,5> a1 = {1,2,3,4,5};

    cout<<a1[2]<<" :access array";

    a1.fill(8);

    for(auto num : a1)
    {
        cout<<num<<" ";
    }

    cout<<endl;
    int sum2 = accumulate(a1.begin(),a1.end(),10);
    cout<<sum2<<" :sum2";
    cout<<endl;

    int count8 = count(a1.begin(),a1.end(),8);
    cout<<count8<<" :count8";
    cout<<endl;

    int x=4, y=12;
    int lcm1 = lcm(x,y);
    cout<<lcm1<<" :lcm1"<<endl;


    set<int> s1 = {1,2,2,3,4,9,7,6}; //add multi
    s1.insert(3);
    s1.insert(10);

    for(int val : s1)
    {
        cout<<val<<" "; //op 1 2 3 4 6 7 9 10 //if multiset 1 2 2 3 3 4 6 7 9 10
    }

    cout<<endl;

    auto it = s1.find(100);

    if(it != s1.end())
    {
        cout<<"Element found : "<<*it<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }

    //by simple for loop and && we can perform this operation but
    //by using below approach we are doing it in logarithmic time
    //Binary search tree

    auto minNum = lower_bound(s1.begin(),s1.end(),3);
    auto maxNum = lower_bound(s1.begin(),s1.end(),6);

    for(auto it=minNum; it!=maxNum; it++)
    {
        cout<<*it<<" ";
    }

    cout<<endl;

    int nz = 3;
    for(int i=0; i < (1 << nz); i++)
    {
        cout<<i<<" :Exponential time"<<endl;
    }

    for(int i=0; i < pow(2,3); i++)
    {
        cout<<i<<" :pow Exponential time"<<endl;
    }

    auto start3 = std::chrono::high_resolution_clock::now();
    cout<<pow(2,32)<<" :2^32 value"<<endl;
    auto end3 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<chrono::duration<double>>(end3-start3);

    cout<<"Time :"<<duration.count()<<endl;

    int exp = 17;
    long long int  num = 0;
    for(int i=0; i < (1LL << exp); i++)
    {
        num++;
    }

    cout<<num<<" :num"<<endl;

    cout<<(1ULL << 32)<<" 2 power 32 value"<<endl;

    // LARGEST SUM OF NUMBER IN 64 BIT PC
    unsigned __int128 N = ((unsigned __int128)1 << 64) - 1;
    unsigned __int128 sum7 = N * (N + 1) / 2;

    // Convert to string safely without shifting
    unsigned __int128 temp = sum7;
    std::string str;
    do {
        str = char('0' + temp % 10) + str;
        temp /= 10;
    } while (temp != 0);

    std::cout << "Sum = " << str << std::endl;

    int ji = 123;

    string jis = to_string(ji);

    cout<<jis<<endl;

    char jis2 = char('0'+1);
    cout<<jis2<<endl;

    int a = 45;
    float b = 0.67;

    float total = a+b;
    cout<<total<<endl;

    // 3D heterogeneous data structure

    typedef map<string,int> areaCode;
    typedef map<string,areaCode> districtData;

    districtData dist1;
    dist1["Nellore"]["Narkur"] = 524314;
    dist1["Nellore"]["Vedayapalem"] = 524004;

    dist1["Chittor"]["Kalikiri"] = 524174;

    cout<<dist1["Nellore"]["Narkur"]<<endl;
    cout<<dist1["Chittor"]["Kalikiri"]<<endl;

    //Iterations
    for (const auto& district : dist1) {
        const std::string& districtName = district.first;
        const areaCode& areas = district.second;

        std::cout << "District: " << districtName << std::endl;

        for (const auto& pin : areas) {
            std::cout << "  Area: " << pin.first
                      << ", Code: " << pin.second << std::endl;
        }
    }


    //For file handling
    ofstream outfile("details.txt",ios::out);

    if(!outfile)
    {
        cerr<<"Error opening file"<<endl;
    }


    // School Data using typedef and map (heterogeneous data) + O(logN) lookups
    // Top rankers from schools with grade
    using department = map<string,vector<int>>;
    using school     = map<string,department>;

    school schools;
    schools["Nagarjuna EM School"]["7th grade"] = {311,334};
    schools["Nagarjuna EM School"]["6th grade"] = {308};

    schools["Audisankara EM School"]["5th grade"] = {338,337};

    for(const auto& schoolName : schools)
    {
        cout<<schoolName.first<<" :"<<endl;
        outfile<<schoolName.first<<" :"<<endl;

        auto const& departmentDetails = schoolName.second;

        for(auto const& details : departmentDetails)
        {
            cout<<details.first<<" : ";
            outfile<<details.first<<" : ";

            for(auto it = details.second.begin(); it != details.second.end(); it++)
            {
                cout<<*it;
                outfile<<*it;

                if(next(it) != details.second.end())
                {
                    cout<<",";
                    outfile<<",";
                }
            }

            cout<<endl;
            outfile<<endl;
        }
    }

    cout<<endl;
    cout<<"Writing to file completed !!!"<<endl;

    outfile.close();

    zubair::print();

    using namespace zubair;

    int res3 = square(12);
    cout<<endl<<res3<<endl;
    print();


    map<int,string> student;
    student[1] = "Zubair";
    student[2] = "Anas";

    student[2] = "Ansar"; // Key must be unique otherwise it will overwrite

    student.insert({4,"Haris"}); //It internally uses std::pair

    auto it1 = student.find(2);

    if(it1 != student.end())
    {
        cout<<it1->second<<endl;
    }

    for(const auto& [roll,names] : student)
    {
        cout<<roll<<"->"<<names<<endl;
    }

    student.erase(4);

    cout<<student.size()<<" :size"<<endl;

    //Multi map
    multimap<int,string> studentMulti;


    studentMulti.insert({4,"Haris"}); //It internally uses std::pair
    studentMulti.insert({4,"Hameed"});
    studentMulti.insert({2,"Ravi"});
    studentMulti.insert({3,"Ramesh"});
    studentMulti.insert({3,"Rakesh"});
    studentMulti.insert({1,"Zubair"});

    auto it2 = studentMulti.find(2);

    if(it2 != studentMulti.end())
    {
        cout<<it2->second<<endl;
    }

    for(const auto& [roll,names] : studentMulti)
    {
        cout<<roll<<"->"<<names<<endl;
    }

    cout<<studentMulti.count(4)<<" :count"<<endl;

    //lower_bound(), upper_bound() and equal_range()

    auto it3 = studentMulti.lower_bound(1);
    cout<<it3->second<<" :lower_bound(1)"<<endl;

    auto it4 = studentMulti.upper_bound(2);
    cout<<it4->second<<" :upper_bound(2)"<<endl;

    auto it5 = studentMulti.equal_range(3);

    for(auto it = it5.first; it != it5.second; it++)
    {
        cout<<it->first<<","<<it->second<<endl;
    }

    studentMulti.erase(4);

    cout<<studentMulti.size()<<" :size"<<endl;

    // UTILITIES
    //std::pair ******************************************************************************
    //C++17 CTAD creation Class Template Argument Deduction
    pair p1{6,8};
    pair p2{5,1};


    if(p1>p2)
        cout<<"p1 is greater"<<endl;

    //constructor creation
    pair<int,string> k1(1,"India");
    cout<<k1.first<<","<<k1.second<<endl;

    // Automatic type deduction
    auto y1 = make_pair(67,89.2);
    cout<<y1.first<<","<<y1.second<<endl;


    //std::tuple ***************************************************************************
    tuple<int,string,double> t1(1,"Qt",6.91);
    cout<<get<0>(t1)<<endl;
    cout<<get<1>(t1)<<endl;
    cout<<get<2>(t1)<<endl;

    auto t2 = make_tuple(45,"Zubair",4.5);

    auto t3 = t2;

    int number;
    string name;
    float pointVal;

    tie(number,name,pointVal) = t3;

    cout<<number<<" "<<name<<" "<<pointVal<<endl;

    auto merged = tuple_cat(t1,t3);
    cout<<get<0>(merged)<<endl;
    cout<<get<1>(merged)<<endl;
    cout<<get<2>(merged)<<endl;
    cout<<get<3>(merged)<<endl;
    cout<<get<4>(merged)<<endl;
    cout<<get<5>(merged)<<endl;

    //std::optional C++17 thing ***************************************************************
    // For returning functions if some thing bad happens

    // not -1 or nullptr or "" just use nullopt, has_value(), user.value

    auto user = findUser(43);

    if(user.has_value())
    {
        cout<<"We found user"<<" "<<user.value();
    }
    else
    {
        cout<<"No Val"<<endl;
    }


    variant<int,double,string> data;

    data = "lala";
    data = 3.14;
    data = 5;

    //cout<<get<double>(data)<<endl;

    if (holds_alternative<double>(data)) {
        cout << get<double>(data) << endl;
    } else if (holds_alternative<int>(data)) {
        cout << "We have int data type in data";
    } else {
        cout << "No currently int or double is active";
    }


    any a5 = 10;
    a5 = 10.45;
    a5 = string("Zubair");

    try
    {
        cout<<endl<<any_cast<string>(a5)<<endl;
    }
    catch(const bad_any_cast &e)
    {
        cout<<endl<<e.what()<<endl;
    }
    catch (...)
    {
        cout<<"Hello buddy we are suck"<<endl;
    }


    // Functors and for_each()
    vector<int> v10 = {1,2,3,4,5,6};
    Counter c = for_each(v10.begin(),v10.end(),Counter{});
    cout<<c.count<<" : Even nums count"<<endl;

    square1 s10;
    cout<<s10(5)<<" : square"<<endl;

    vector<int> p(10,s10(5));
    printVectorRef(p);

    //Brief intro about functional

    plus<int> add;
    cout<<add(10,20)<<" :plus struct"<<endl;

    greater<int> cmp;
    cout<<cmp(71,70)<<" :greater struct"<<endl;


    function<void(int,string)> func;
    func = normalFunc;
    func(24,"Zubair");

    auto another = bind(normalFunc,25,placeholders::_1);
    another("Zubair");

    //Smart Pointers
    foo *obj = new foo(); // OR auto obj = new foo;
    delete obj;

    unique_ptr<foo> obj4 = make_unique<foo>();


    {
        cout<<"Inside scope"<<endl;
        cout<<obj->k<<endl;
        cout<<obj4->k<<endl;
    }

    //auto obj5 = obj4; //Error in unique there is only move not copy
    auto obj5 = std::move(obj4);

    shared_ptr<sharing> sObj = make_shared<sharing>();

    {
        cout<<"Inside sharing scope"<<endl;
        auto sObj2 = sObj;
        cout<<sObj2->k<<endl; //sObj2 is owner of k
        cout<<"Does it creating twice"<<endl;
    }

    cout<<sObj->k<<endl; //sObj is also owner of k they will destroy accordingly


    //# MULTITHREADING
    future<int> result = async(launch::async,heavyWork,5);

    vector<string> strf(10,"Main Thread Running ..");

    for(const auto& stringName : strf)
    {
        cout<<stringName<<endl;
    }


    while (result.wait_for(std::chrono::milliseconds(100)) != std::future_status::ready) { //Why should i wait here when i go down and print go go pow
        cout << "Still working..." << endl;
    }


    cout << result.get() << endl;
    cout << "Go go ... Power Rangers" << endl;

    //# Continue MULTITHREADING With thread and detach but this way can't guarantee if main returns your threads get killed

    future<int> result2 = async(launch::async,heavyWork,2);

    thread([&result2]() mutable {
        cout<<result2.get()<<" :we are getting 2sec heavywork"<<endl;
    }).detach();


    cout<<"Shinzo Sasageyo ..."<<endl;

    //# this method prevents sudden main returning watcher.join() ----------------------- OG METHOD

    future<int> result3 = async(launch::async,heavyWork,3);

    thread watcher  ([&result3]() mutable {
        cout<<result3.get()<<" :we are getting 3sec heavywork"<<endl;
    });


    cout<<"Shinzo Sasageyo part 2 ..."<<endl;

    watcher.join();

    //Mutex real usage
    future<int> thread1 = async(launch::async,task1,1'00'000);
    future<int> thread2 = async(launch::async,task1,1'00'000);


    cout<<thread1.get()<<" :thread1.get()"<<endl;
    cout<<thread2.get()<<" :thread2.get()"<<endl;

    cout<<heavyCounter<<" :heavyCounter"<<endl;

    //QTimer like structure

    thread printMyNameEverySec(printFunc);

    printMyNameEverySec.join();

    future<int> result100 = async(launch::async,printFunc2);

    thread watcher2 ([&result100](){
        cout<<result100.get()<<" : result100.get()"<<endl;
    });


    cout<<"Done Printing"<<endl;
    watcher2.join();

    return 0;
}

optional<string> findUser(int num)
{
    if(num == 42)
    {
        return "Zubair";
    }
    return nullopt;
}

int task1(int c)
{
    for(int i=0;i<c;i++)
    {
        lock_guard<mutex> lock(mtx);
        heavyCounter++;
    }
    return 999;
}

void printFunc()
{
    for(int i=0; i<20; i++)
    {
        safePrintingStr("Shaik Zubair ahmad");
        this_thread::sleep_for(100ms);
    }
}

int printFunc2()
{
    for(int i=0; i<30; i++)
    {
        safePrintingStr("Shaik Zubair ahmad future");
        this_thread::sleep_for(100ms);
    }

    return 1001;
}




