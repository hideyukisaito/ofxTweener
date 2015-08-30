/*
 *  ofxTweener.h
 *  openFrameworks
 *
 *  Created by Sander ter Braak on 26-08-10.
 *
 *  Forked by Hideyuki Saito on 30-08-15
 *
 */

#include "ofMain.h"
#include "ofxTransitions.h"

#ifndef _OFXTWEEN
#define _OFXTWEEN

#define TWEENMODE_OVERRIDE 0x01
#define TWEENMODE_SEQUENCE 0x02

template<typename T = double>
class Tween {
public:
	typedef T(ofxTransitions<T>::* easeFunction)(T,T,T,T);
	T* _var;
	T _from, _to, _duration,_by, _useBezier;
	easeFunction _easeFunction;
	Poco::Timestamp _timestamp;
};


template<typename T = double>
class ofxTweener : public ofBaseApp {

public:
	
	ofxTweener();
    
    void addTween(T &var, T to, T time, void (^callback)(T * arg)=NULL);
    void addTween(T &var, T to, T time, T (ofxTransitions<T>::*ease) (T,T,T,T), void (^callback)(T * arg)=NULL);
    void addTween(T &var, T to, T time, T (ofxTransitions<T>::*ease) (T,T,T,T), T delay, void (^callback)(T * arg)=NULL);
    void addTween(T &var, T to, T time, T (ofxTransitions<T>::*ease) (T,T,T,T), T delay, T bezierPoint, void (^callback)(T * arg)=NULL);
    
    void removeTween(T &var);
    void setTimeScale(T scale);
    void update();
    void removeAllTweens();
    void setMode(int mode);
    
    size_t getTweenCount();
	
	
private:
    void addTween(T &var, T to, T time, T (ofxTransitions<T>::*ease) (T,T,T,T), T delay, T bezierPoint, bool useBezier, void (^callback)(T * arg)=NULL);
    
	T _scale;
	ofxTransitions<T> a;
	bool _override;
	T bezier(T b, T e, T t, T p);
	vector<Tween<T> > tweens;
    std::map<T *, void (^)(T * arg)> callbacks;
    
};

#endif