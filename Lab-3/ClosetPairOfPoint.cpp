#include<bits/stdc++.h>
using namespace std;
class point{
public:
    int x;
    int y;
};

int CompareX(const void* a,const void * b){
    point *p1=(point *)a;
    point *p2=(point *)b;
    return (p1->x-p2->x);

}

int CompareY(const void*a,const void*b){
    point *p1=(point *)a;
    point *p2=(point *)b;
    return (p1->y-p2->y);
}

float dist(point p1,point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

float bruteForce(point p[],int n){
    float min=FLT_MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(dist(p[i],p[j])<min){
                min= dist(p[i],p[j]);
            }
        }
    }
    return min;

}

float min(float  x,float y){
    return (x<y)?x:y;
}

float stripCloset(point strip[],int  size,float d){
    float min=d; //initialize the minimum distance as d
    qsort(strip,size,sizeof(point),CompareY);
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size &&(strip[j].y-strip[i].y)<min; j++){
            if(dist(strip[i],strip[j])<min){
                min=dist(strip[i],strip[j]);
            }
        }
    }
    return min;
}
float ClosetUtil(point p[],int n){
    if(n<=3){
        return bruteForce(p,n);
    }
    int mid=n/2;
    point midpoint=p[mid];
    float dl= ClosetUtil(p,mid);
    float  dr= ClosetUtil(p+mid,n-mid);
    float d=min(dl,dr);

    point strip[n];
    int j=0;
    for(int i=0; i<n; i++){
        if(abs(p[i].x-midpoint.x)<d){
            strip[j]=p[i],j++;
        }
    }
    return min(stripCloset(strip,j,d),d);
}
float closet(point p[],int n){
    qsort(p,n, sizeof(point),CompareX);
    return ClosetUtil(p,n);
}
int main() {

point p[]={{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
    int n=sizeof (p)/sizeof (p[0]);
    cout << "The smallest distance is " << ClosetUtil(p, n);

}

