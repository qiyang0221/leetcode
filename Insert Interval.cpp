//
//description:
//给一组不重叠的区间
//再给一个新的区间
//生成一组新的区间
//
//solution:
//细节题，先找到第一个大于当前区间的区间进行合并，然后逐个合并就好了 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        
        int i;
        for(i=0;i<intervals.size() && newInterval.start > intervals[i].end;i++)
        	res.push_back(intervals[i]);
        	
        if( i == intervals.size()){
        	res.push_back(newInterval);
        	
        	return res;
        }
        
        int start = i;
        for(;i<intervals.size() && newInterval.end > intervals[i].end;i++);
        int end = i;
        if(end == intervals.size()){
        	if(intervals[start].start < newInterval.start)
        		res.push_back(Interval(intervals[start].start,newInterval.end));
        	else
        		res.push_back(newInterval);
        }else{
        	if(newInterval.end < intervals[start].start){
        		res.push_back(newInterval);
        	}else{
	        	if(newInterval.end < intervals[end].start){
	        		if(newInterval.start <  intervals[start].start)
	        			res.push_back(newInterval);
	        		else
	        			res.push_back(Interval(intervals[start].start,newInterval.end));
	        	}else{
	        		if(intervals[start].start < newInterval.start){
	        			res.push_back(Interval(intervals[start].start,intervals[end].end));
		        	}else{
		        		res.push_back(Interval(newInterval.start,intervals[end].end));
		        	}
		        	i++;
	        	}
        	}
        }
        
        for(i;i<intervals.size();i++){
        	res.push_back(intervals[i]);
        }
        
        for(i=0;i<res.size();i++){
        	printf("[%d,%d] ",res[i].start,res[i].end);
        }
        cout<<endl;
        return res;
    }
};

int main(){
	Solution s;
	
	vector<Interval> intervals;
	Interval interval1(1,4);
	Interval interval2(9,12);
	Interval interval3(19,22);
	//Interval interval4(8,10);
	//Interval interval5(12,16);
	Interval interval6(7,13);
	
	intervals.push_back(interval1);
	intervals.push_back(interval2);
	intervals.push_back(interval3);
	//intervals.push_back(interval4);
	//intervals.push_back(interval5);
	s.insert(intervals,interval6);
}
