/*
 * ROS Node C++ boiler template
 * Authors: Joe Ferreira Scholtz and Julio Chi
 */

//includes
#include "ros/ros.h"

//defines
//constants
//using
using std::string
//typdefs
//structs
//class
class MyNode{
public:
    //Constructor
    MyNode(){
       //Node Handle in private namespace to get parameters
        nh_private = ros::NodeHandle("~"); 

        //Getting parameters
        nh_private.param<string>("sub_topic_name",sub_topic_name,"/sub_topic_name");
        nh_private.param<string>("pub_topic_name",pub_topic_name,"/pub_topic_name");

        //Topics to publish
        singleStatePub = nh.advertise<std_msgs::Float64>(singleStateTopicName, 10);

        //Topics to subscribe        
        rawJointStateSub = nh.subscribe(rawJointStateTopicName, 1, &Splitter::rawJointStateCallback, this);
    }
    void Callback(const string)
private:
    //ROS Node stuff
    ros::NodeHandle nh;
    ros::NodeHandle nh_private;
    ros::Publisher pub;
    ros::Subscriber sub;
    //Parameters
    string sub_topic_name, pub_topic_name;
};

int main(int argc, char** argv){
    //Initialize ROS Node
    ros::init(argc,argv,"MyNode");
    //Instantiate class
    MyNode myNode;
    //loop
    double f = 10; //rate frequency
    ros::Rate r(f);
    while (ros::ok()){
        r.sleep();
        ros::spinOnce();
    }

    return 0;
}