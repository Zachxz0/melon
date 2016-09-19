#include <iostream>
#include <fstream>
#include <vector>
#include <melon/log_neuron.hpp>
#include <string>
#include <melon/mat.hpp>
#include <melon/vec.hpp>
#include <melon/reader.hpp>
#include <utils/timer.hpp>
#include <boost/shared_ptr.hpp>
#include <melon/linear_neuron.hpp>
#include <melon/layer.hpp>
#include <melon/stump_neuron.hpp>
#include <zoson/object.hpp>
#include <thread>
#include <melon/softmax_neuron.hpp>
using namespace boost;
using namespace melon;
using namespace std;
void change(Vector<double> * vec)
{
	(*vec)[0] = 1.22;
	(*vec)[1] = 23.22;
}

void testMatAndVec()
{
	Matrix<double> mat(3,2) ;
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[1][0] = 3;
	mat[1][1] = 4;
	mat[2][0] = 5;
	mat[2][1] = 6;
	cout<<mat.print();
	cout<<"mat transpose"<<endl;
	cout<<mat.transpose().print();

	Vector<double>* vec = new Vector<double>(3,1);
	change(vec);
	cout<<vec->print();
}

void testReader()
{
	Reader<double,int> reader("/Users/Zoson/Desktop/ml/Ch05/testSet.txt");
	Matrix<double> mat;
	Vector<int> vec;
	reader.getAll(mat,vec);
	cout<<mat.print();
	cout<<vec.print();
}

void testLogNeuron()
{
	//Timer t(Timer::AUTO);
	//boost::progress_timer t;
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch05/horseColicTraining.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label,22);
	mat.insertCol();
	LogNeuron log;
	log.setLearningRate(0.1);
	cout<<"dim:"<<mat.getCol()<<endl;;
	log.initSpec(mat.getCol());
	for(int i=0;i<1000;++i)
	{
		try{
			Vector<double>* outs = log.forward(&mat);
			Vector<double> delta =  *(outs) - label;
			Matrix<double>* pre_delta = log.backward(&delta);
			log.updateWeight();
		}catch(...)
		{
			cout<<"cat"<<endl;
		}
		
	}
	cout<<log.print();
	Reader<double,double> testreader("/Users/Zoson/Desktop/ml/Ch05/horseColicTest.txt");
	Matrix<double> test_mat;
	Vector<double> test_vec;
	testreader.getAll(test_mat,test_vec,22);
	test_mat.insertCol();
	int row = test_mat.getRow();
	int corr = 0;
	for(int i=0;i<test_vec.getDim();++i)
	{
		if(log.test(&test_mat[i])==test_vec[i])
		{
			corr++;
		}
	}
	cout<<"correct_rate:"<<(double)corr/row<<endl;
}

void testLinearNeuron()
{
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch08/ex1.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label);
	LinearNeuron lin;
	lin.initSpec(mat.getCol());
	for(int i=0;i<500;++i)
	{
		try{
			Vector<double>* outs = lin.forward(&mat);
			Vector<double> delta = *(outs) - label;
			Matrix<double>* pre_delta = lin.backward(&delta);
			lin.updateWeight();
		}catch(...)
		{
			cout<<"cat"<<endl;
		}
		
	}
	cout<<lin.print();
}


void testLayer()
{
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch08/ex1.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label);
	Layer layer ;
	LinearNeuron *lin = new LinearNeuron();
	lin->initSpec(mat.getCol());
	layer.push(lin);
	for(int i=0;i<20;++i)
	{
			Vector<double>* outs = lin->forward(&mat);
			//Matrix<double> mlabel;
			//mlabel.insertRow(label);
			Vector<double> delta =  *(outs) - label;
			Matrix<double>* pre_delta = lin->backward(&delta);
			lin->updateWeight();
	}
	cout<<layer.print();
}

void testStumpNeuron()
{
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch07/test.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label);
	cout<<mat.print();
	cout<<label.print();
	Vector<double> *weight = new Vector<double>(mat.getRow(),(double)1.0/mat.getRow());
	for(int i=0;i<3;++i)
	{
		StumpNeuron *stu = new StumpNeuron();
		double a = stu->innerDigest(&mat,&label,weight);
		cout<<stu->print();
		cout<<"alpha:"<<a<<endl;
	}
}

zoson::Object obj;
void testCond()
{
	obj.wait();
}

void notifyThread()
{
	obj.notifyAll();
}
void testObject()
{
	std::thread t1(testCond);
	std::thread t2(testCond);		
	for(int i=0;i<100000;i++);	
	notifyThread();
	t1.join();
	t2.join();

}

#define tr_im "/Users/Zoson/Downloads/softmax_data_and_code/train-images.idx3-ubyte"
#define tr_la "/Users/Zoson/Downloads/softmax_data_and_code/train-labels.idx1-ubyte"
#define te_im "/Users/Zoson/Downloads/softmax_data_and_code/t10k-images.idx3-ubyte"
#define te_la "/Users/Zoson/Downloads/softmax_data_and_code/t10k-labels.idx1-ubyte"

void testSoftMax()
{
	Reader<double,double> reader("/Users/Zoson/Desktop/ml/Ch05/horseColicTraining.txt");
	Matrix<double> mat;
	Vector<double> label;
	reader.getAll(mat,label,22);
	mat.insertCol();
	SoftMaxNeuron log;
	log.initSpec(2,22,0.1);
	for(int i=0;i<1000;++i)
	{
		try{
			Matrix<double>* outs = log.forward(&mat);
			//Vector<double> delta =  *(outs) - label;
			Matrix<double>* pre_delta = log.backward(&label);
			log.updateWeight();
			if(i%50==0)cout<<log.print();
		}catch(...)
		{
			cout<<"cat"<<endl;
		}
		
	}
	Reader<double,double> testreader("/Users/Zoson/Desktop/ml/Ch05/horseColicTest.txt");
	Matrix<double> test_mat;
	Vector<double> test_vec;
	testreader.getAll(test_mat,test_vec,22);
	test_mat.insertCol();
	int row = test_mat.getRow();
	int corr = 0;
	for(int i=0;i<test_vec.getDim();++i)
	{
		if(log.test(&(test_mat[i]))==test_vec[i])
		{
			corr++;
		}
	}
	cout<<log.print();
	cout<<"correct_rate:"<<(double)corr/row<<endl;
// 	Matrix<double> train_data;
// 	Matrix<double> test_data;
// 	Vector<double> train_label;
// 	Vector<double> test_label;
// 	unsigned char info[16];
// 	int magicImageTrainNum;
// 	int imageTrainNum;
// 	int imageTrainCol;
// 	int imageTrainRow;
// 	unsigned char **imageTrainMatrix;//[60000][28x28]
// 	fstream *fr_tr_im = new fstream(tr_im,ios::in|ios::binary);
// 	fr_tr_im->read((char *)info,16);

// 	magicImageTrainNum = ((info[0]*256+info[1])*256+info[2])*256+info[3];
// 	imageTrainNum = ((info[4]*256+info[5])*256+info[6])*256+info[7];
// 	imageTrainRow = ((info[8]*256+info[9])*256+info[10])*256+info[11];
// 	imageTrainCol = ((info[12]*256+info[13])*256+info[14])*256+info[15];
// //	imageTrainMatrix = zeros(imageTrainNum,imageTrainRow*imageTrainCol);
// 	 int col = imageTrainRow*imageTrainCol;
// 	imageTrainMatrix = new unsigned char*[imageTrainNum];
	
// 	cout<<"magicImageTrainNum="<<magicImageTrainNum<<endl;
// 	cout<<"imageTrainNum="<<imageTrainNum<<endl;
// 	cout<<"imageTrainRow="<<imageTrainRow<<endl;
// 	cout<<"imageTrainCol="<<imageTrainCol<<endl;
// 	cout<<"col="<<col<<endl;	

// 	for(int i=0;i<imageTrainNum;i++)
// 	{	
// 		train_data.insertRow(*(new Vector<double>()));
// 		for(int j=0;j<col;j++)
// 		{
// 			unsigned char temp;
// 			fr_tr_im->read((char *)&temp,1);
// 			double val = 0;
// 			if(temp>0)val = 1;
// 			train_data[i].push(val);
// 			//cout<<(int)temp;
// 			//if(j%28 == 0)cout<<endl;
// 		}
// 		//cout<<endl;
// 	}
// 	fr_tr_im->close();
// 	delete fr_tr_im;
// 	fr_tr_im = NULL;
	
// 	int magicImageTestNum;
// 	int imageTestNum;
// 	int imageTestCol;
// 	int imageTestRow;
// 	unsigned char **imageTestMatrix;
// 	fstream *fr_te_im = new fstream(te_im,ios::in|ios::binary);
// 	fr_te_im->read((char *)info,16);	

// 	magicImageTestNum = ((info[0]*256+info[1])*256+info[2])*256+info[3];
// 	imageTestNum = ((info[4]*256+info[5])*256+info[6])*256+info[7];
// 	imageTestRow = ((info[8]*256+info[9])*256+info[10])*256+info[11];
// 	imageTestCol = ((info[12]*256+info[13])*256+info[14])*256+info[15];
// //	imageTrainMatrix = zeros(imageTrainNum,imageTrainRow*imageTrainCol);
// 	 int col_1 = imageTestRow*imageTestCol;
// 	imageTestMatrix = new unsigned char*[imageTestNum];
	
// 	cout<<"magicImageTestNum="<<magicImageTestNum<<endl;
// 	cout<<"imageTestNum="<<imageTestNum<<endl;
// 	cout<<"imageTestRow="<<imageTestRow<<endl;
// 	cout<<"imageTestCol="<<imageTestCol<<endl;
// 	cout<<"col_1="<<col_1<<endl;	

// 	for(int i=0;i<imageTestNum;i++)
// 	{	
// 		test_data.insertRow(*(new Vector<double>()));
// 		for(int j=0;j<col_1;j++)
// 		{
// 			unsigned char temp;
// 			fr_te_im->read((char *)&temp,1);
// 			double val = 0;
// 			if(temp>0)val = 1;
// 			test_data[i].push(val);
// 		}
// 	}
// 	fr_te_im->close();
// 	delete fr_te_im;
// 	fr_te_im = NULL;


// 	int magiclabelTrainNum;
// 	int labelTrainNum;
// 	unsigned char *labelTrainMatrix;
// 	fstream *fr_tr_la = new fstream(tr_la,ios::in|ios::binary);
// 	fr_tr_la->read((char*)info,8);
// 	magiclabelTrainNum = ((info[0]*256+info[1])*256+info[2])*256+info[3];
// 	labelTrainNum = ((info[4]*256+info[5])*256+info[6])*256+info[7];
// 	labelTrainMatrix = new unsigned char[labelTrainNum];
	
// 	cout<<"magiclabelTrainNum:"<<magiclabelTrainNum<<endl;	
	
// 	for(int i=0;i<labelTrainNum;i++)
// 	{
// 		unsigned char temp;
// 		fr_tr_la->read((char *)&temp,1);
// 		train_label.push(temp);
// 	}
// 	fr_tr_la->close();
// 	delete fr_tr_la;
// 	fr_tr_la = NULL;

// 	int magiclabelTestNum;
// 	int labelTestNum;
// 	unsigned char *labelTestMatrix;
// 	fstream *fr_te_la = new fstream(te_la,ios::in|ios::binary);
// 	fr_te_la->read((char*)info,8);
// 	magiclabelTestNum = ((info[0]*256+info[1])*256+info[2])*256+info[3];
// 	labelTestNum = ((info[4]*256+info[5])*256+info[6])*256+info[7];
// 	labelTestMatrix = new unsigned char[labelTestNum];
	
// 	cout<<"magiclabelTestNum:"<<magiclabelTestNum<<endl;	
	
// 	for(int i=0;i<labelTestNum;i++)
// 	{
// 		unsigned char temp;
// 		fr_te_la->read((char *)&temp,1);
// 		test_label.push(temp);
// 	}
// 	fr_te_la->close();
// 	delete fr_te_la;
// 	fr_te_la = NULL;

// 	SoftMaxNeuron so ;
// 	Matrix<double>* data_t = &(train_data.transpose());
// 	so.initSpec(10,28*28,0.5);
// 	for(int i=0;i<1000;++i)
// 	{
// 		cout<<"train forward"<<endl;
// 		so.forward(&train_data,data_t);
// 		cout<<"train backward"<<endl;	
// 		so.backward(&train_label);
// 		cout<<"train update"<<endl;
// 		so.updateWeight();
// 		cout<<"train end"<<endl;
// 		//cout<<so.print();
// 	}

// 	double rate = 0.0;
// 	double count = 0;
// 	for(int i=0;i<labelTestNum;++i)
// 	{
// 		double res = so.test(test_data[i]);
// 		if((int)res==(int)test_label[i])
// 		{
// 			count++;
// 		}
// 	}
// 	cout<<"correct rate:"<<rate/labelTestNum<<endl;
}

int main()
{
	//testMatAndVec();
	//testReader();
	//testLogNeuron();
	//testLinearNeuron();
	//testLayer();
	//testStumpNeuron();
	//testObject();
	testSoftMax();
}
