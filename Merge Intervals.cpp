//
//description:
//给定一组重叠区间[i,j]，归并重叠部分，返回不重叠缺件
//
//solution:
//先按照[i,j]i进行排序，然后如果j1 > i2就需要归并
//复杂度O(nlogn) 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &a,const Interval &b){
		return a.start < b.start;
}
	
class Solution {
public:
	
	
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        
        if(intervals.size() <= 0)
        	return res;
        sort(intervals.begin(),intervals.end(),cmp);
        
        Interval newInterval(intervals[0].start,intervals[0].end);
        for(int i=1;i<intervals.size();i++){
        	if(intervals[i].start > newInterval.end){
        		res.push_back(Interval(newInterval.start,newInterval.end));
        		newInterval.start = intervals[i].start;
        		newInterval.end = intervals[i].end;
        	}else{
        		newInterval.end = newInterval.end > intervals[i].end ? newInterval.end : intervals[i].end;
        	}
        }
        
        res.push_back(Interval(newInterval.start,newInterval.end));
        
        return res;
    }
};


int main(){
	vector<Interval> intervals;
	Interval interval1(1,4);
	Interval interval2(0,4);
	//Interval interval3(3,6);
	//Interval interval4(15,18);
	
	intervals.push_back(interval1);
	intervals.push_back(interval2);
	//intervals.push_back(interval3);
	//intervals.push_back(interval4);
	
	Solution s;
	vector<Interval> res = s.merge(intervals);
	for(int i=0;i<res.size();i++){
		printf("[%d,%d] ",res[i].start,res[i].end);
	}
	printf("\n");
}
