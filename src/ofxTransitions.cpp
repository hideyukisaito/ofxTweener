#include "ofxTransitions.h"

template<typename T>
T ofxTransitions<T>::linear(T t,T b , T c, T d){
	return c*t/d + b;
}

template<typename T>
T ofxTransitions<T>::easeInSine(T t,T b , T c, T d){
	return -c * cos(t/d * (PI/2)) + c + b;
}
template<typename T>
T ofxTransitions<T>::easeOutSine(T t,T b , T c, T d){
	return c * sin(t/d * (PI/2)) + b;
}
template<typename T>
T ofxTransitions<T>::easeInOutSine(T t,T b , T c, T d){
	return -c/2 * (cos(PI*t/d) - 1) + b;
}

template<typename T>
T ofxTransitions<T>::easeInCubic(T t,T b , T c, T d){
	return c*(t/=d)*t*t + b;
}
template<typename T>
T ofxTransitions<T>::easeOutCubic(T t,T b , T c, T d){
	return c*((t=t/d-1)*t*t + 1) + b;
}
template<typename T>
T ofxTransitions<T>::easeInOutCubic(T t,T b , T c, T d){
	if ((t/=d/2) < 1) return c/2*t*t*t + b;
	return c/2*((t-=2)*t*t + 2) + b;
}

template<typename T>
T ofxTransitions<T>::easeInQuint(T t,T b , T c, T d){
	return c*(t/=d)*t*t*t*t + b;
}
template<typename T>
T ofxTransitions<T>::easeOutQuint(T t,T b , T c, T d){
	return c*((t=t/d-1)*t*t*t*t + 1) + b;
}
template<typename T>
T ofxTransitions<T>::easeInOutQuint(T t,T b , T c, T d){
	if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
	return c/2*((t-=2)*t*t*t*t + 2) + b;
}


template<typename T>
T ofxTransitions<T>::easeInCirc(T t,T b , T c, T d){
	return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
}
template<typename T>
T ofxTransitions<T>::easeOutCirc(T t,T b , T c, T d){
	return c * sqrt(1 - (t=t/d-1)*t) + b;
}
template<typename T>
T ofxTransitions<T>::easeInOutCirc(T t,T b , T c, T d){
	if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
	return c/2 * (sqrt(1 - t*(t-=2)) + 1) + b;
}


template<typename T>
T ofxTransitions<T>::easeInBack(T t,T b , T c, T d){
	T s = 1.70158f;
	T postFix = t/=d;
	return c*(postFix)*t*((s+1)*t - s) + b;
}
template<typename T>
T ofxTransitions<T>::easeOutBack(T t,T b , T c, T d){
	T s = 1.70158f;
	return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}	
template<typename T>
T ofxTransitions<T>::easeInOutBack(T t,T b , T c, T d){
	T s = 1.70158f;
	if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + b;
	T postFix = t-=2;
	return c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + b;
}


template<typename T>
T ofxTransitions<T>::easeInQuad(T t,T b , T c, T d){
	return c*(t/=d)*t + b;
}
template<typename T>
T ofxTransitions<T>::easeOutQuad(T t,T b , T c, T d){
	return -c *(t/=d)*(t-2) + b;
}
template<typename T>
T ofxTransitions<T>::easeInOutQuad(T t,T b , T c, T d){
	if ((t/=d/2) < 1) return ((c/2)*(t*t)) + b;
	return -c/2 * (((--t)*(t-2)) - 1) + b;
}

template<typename T>
T ofxTransitions<T>::easeInQuart(T t,T b , T c, T d){
	return c*(t/=d)*t*t*t + b;
}
template<typename T>
T ofxTransitions<T>::easeOutQuart(T t,T b , T c, T d){
	return -c * ((t=t/d-1)*t*t*t - 1) + b;
}
template<typename T>
T ofxTransitions<T>::easeInOutQuart(T t,T b , T c, T d){
	if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
	return -c/2 * ((t-=2)*t*t*t - 2) + b;
}

template<typename T>
T ofxTransitions<T>::easeInExpo(T t,T b , T c, T d){
	return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}
template<typename T>
T ofxTransitions<T>::easeOutExpo(T t,T b , T c, T d){
	return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
}
template<typename T>
T ofxTransitions<T>::easeInOutExpo(T t,T b , T c, T d){
	if (t==0) return b;
	if (t==d) return b+c;
	if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
	return c/2 * (-pow(2, -10 * --t) + 2) + b;
}


template<typename T>
T ofxTransitions<T>::easeInElastic(T t,T b , T c, T d){
	if (t==0) return b;  if ((t/=d)==1) return b+c;
	T p=d*.3f;
	T a=c;
	T s=p/4;
	T postFix =a*pow(2,10*(t-=1)); 
	return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
}
template<typename T>
T ofxTransitions<T>::easeOutElastic(T t,T b , T c, T d){
	if (t==0) return b;  if ((t/=d)==1) return b+c;
	T p=d*.3f;
	T a=c;
	T s=p/4;
	return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
}
template<typename T>
T ofxTransitions<T>::easeInOutElastic(T t,T b , T c, T d){
	if (t==0) return b;  if ((t/=d/2)==2) return b+c;
	T p=d*(.3f*1.5f);
	T a=c;
	T s=p/4;
	
	if (t < 1) {
		T postFix =a*pow(2,10*(t-=1));
		return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
	}
	T postFix =  a*pow(2,-10*(t-=1)); 
	return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
}


template<typename T>
T ofxTransitions<T>::easeInBounce(T t,T b , T c, T d){
	return c - easeOutBounce (d-t, 0, c, d) + b;
}
	
template<typename T>
T ofxTransitions<T>::easeOutBounce(T t,T b , T c, T d){
	if ((t/=d) < (1/2.75f)) {
		return c*(7.5625f*t*t) + b;
	} else if (t < (2/2.75f)) {
		T postFix = t-=(1.5f/2.75f);
		return c*(7.5625f*(postFix)*t + .75f) + b;
	} else if (t < (2.5/2.75)) {
		T postFix = t-=(2.25f/2.75f);
		return c*(7.5625f*(postFix)*t + .9375f) + b;
	} else {
		T postFix = t-=(2.625f/2.75f);
		return c*(7.5625f*(postFix)*t + .984375f) + b;
	}
}

template<typename T>
T ofxTransitions<T>::easeInOutBounce(T t,T b , T c, T d){
	if (t < d/2) return easeInBounce (t*2, 0, c, d) * .5f + b;
	else return easeOutBounce (t*2-d, 0, c, d) * .5f + c*.5f + b;
}

template class ofxTransitions<float>;
template class ofxTransitions<double>;