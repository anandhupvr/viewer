#include "DepthSubscriber.h"
#include "RGBSubscriber.h"



int main(int argc, char **argv)
{

	ros::init(argc, argv, "test_node");
	ros::NodeHandle nh;
	DepthSubscriber* depthsub;
	RGBSubscriber* rgbsub;

	depthsub  = new DepthSubscriber("/ROBOTIKA_X1/front/depth", nh);
	rgbsub = new RGBSubscriber("/ROBOTIKA_X1/front/image_raw", nh);




	cv::Mat img;
	while (ros::ok())
	{
		img = depthsub->read();
		// img = rgbsub->read();


		if (img.empty()) 
		{
			ros::spinOnce();
			continue;
		}




	}


}