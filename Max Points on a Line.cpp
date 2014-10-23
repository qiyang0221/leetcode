//
//description:
//2D平面的一组点，求在同一条线上的最多点有多少个 
//
//solution:
//这里以点为中心，采用一个map<double,int>计算斜率
//然后同样的节点再最后确认，就不需要排序了
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;


struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

bool cmp(const Point &m,const Point &n){
	if(m.x == n.x)
		return m.y < n.y;
	return m.x < n.x;
}

struct cmpkey{
   bool operator()(const Point &m,const Point &n){
   		if(m.x == n.x)
			return m.y < n.y;
		return m.x < n.x;
   }
		
}; 
 
class Solution {
public:
	int gcd(int a,int b){
		if(a < b)
			return gcd(b,a);
		if(b == 0)
			return a;
		return gcd(b,a%b);
	}
	
	bool issame(Point &a,Point &b){
		if(a.x == b.x && a.y == b.y)
			return true;
		return false;
	}
    int maxPoints(vector<Point> &points) {
        vector<Point> line;
        int size = points.size();
        if(size <= 1)
        	return size;
        	
        sort(points.begin(),points.end(),cmp);
        
       
        int max = 0;
        for(int i=0;i<size;i++){
        	 map<Point,int,cmpkey> mp;
        	if(i >=1 && issame(points[i],points[i-1]))
        		continue;
        	int same = 0;
        	int j;
        	for(j=i+1;j<size&&issame(points[i],points[j]);j++)
        		same++;
        	vector<Point> line;
        	for(;j<size;j++){
        		int x = points[i].x - points[j].x;
        		int y = points[i].y - points[j].y;
        		if(x == 0 || y == 0){
        			if(x == 0){
        				Point p(points[i].x,0); 
        				line.push_back(p);
        			}
        				
        			if(y == 0){
        				Point p(0,points[i].y); 
        				line.push_back(p);	
        			}
						
        		}else{
        			if(x< 0 && y < 0){
        				x = -x;
        				y = -y;
        			}
        			
        			int c = gcd(abs(x),abs(y));
        			x = x / c;
        			y = y / c;
        			Point p(x,y);
        			line.push_back(p);
        		}
        	}
        	
        	sort(line.begin(),line.end(),cmp);
        	int line_size = line.size();
        	if(line_size > 0){
        		int cnt = 1;
	        	for(int j=1;j<line_size;j++){
	        		if(issame(line[j],line[j-1]))
	        			cnt++;
	        		else{
	        			if(mp[line[j-1]] == 0)
	        				mp[line[j-1]]++;
	    				mp[line[j-1]] = mp[line[j-1]] + same + cnt;
	    				if(mp[line[j-1]] > max)
	    					max = mp[line[j-1]];
	        			cnt= 1;
	        		}
	        	}
	        	if(mp[line[line_size-1]] == 0)
    				mp[line[line_size-1]]++;
				mp[line[line_size-1]] = mp[line[line_size-1]] + same + cnt;
				if(mp[line[line_size-1]] > max)
					max = mp[line[line_size-1]];
        	}else{
        		if(same + 1 > max)
        			max = same+1;
        	}
        	
        }
        
        return max;
    }
};

int main(){
	vector<Point> points;
	Point point1(0,0);
	Point point2(-1,-1);
	Point point3(2,2);
	Point point4(2,2);
	Point point5(1,2);
	
	points.push_back(point1);
	points.push_back(point2);
	points.push_back(point3);
	//points.push_back(point4);
	//points.push_back(point5);
	
	Solution s;
	cout<<s.maxPoints(points)<<endl;
}
