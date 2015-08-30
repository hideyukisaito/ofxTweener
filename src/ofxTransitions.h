/*
 *  ofxTransitions.h
 *  openFrameworks
 *
 *  Created by Sander ter Braak on 27-08-10.
 *  Copyright 2010 hautetechnique.com. All rights reserved.
 *
 *  Forked by Hideyuki Saito on 30-08-15
 *
 */

#include "ofMain.h"

#ifndef _OFXTRANSITIONS
#define _OFXTRANSITIONS

template<typename T = double>
class ofxTransitions{
	public:
		 T linear(T t,T b , T c, T d);
					 
		 T easeInSine(T t,T b , T c, T d);
		 T easeOutSine(T t,T b , T c, T d);
		 T easeInOutSine(T t,T b , T c, T d);

		 T easeInCubic(T t,T b , T c, T d);
		 T easeOutCubic(T t,T b , T c, T d);
		 T easeInOutCubic(T t,T b , T c, T d);
		 
		 T easeInQuint(T t,T b , T c, T d);
		 T easeOutQuint(T t,T b , T c, T d);
		 T easeInOutQuint(T t,T b , T c, T d);
		 
		 T easeInCirc(T t,T b , T c, T d);
		 T easeOutCirc(T t,T b , T c, T d);
		 T easeInOutCirc(T t,T b , T c, T d);
		 
		 T easeInBack(T t,T b , T c, T d);
		 T easeOutBack(T t,T b , T c, T d);
		 T easeInOutBack(T t,T b , T c, T d);
		 
		 T easeInQuad(T t,T b , T c, T d);
		 T easeOutQuad(T t,T b , T c, T d);
		 T easeInOutQuad(T t,T b , T c, T d);
		 
		 T easeInQuart(T t,T b , T c, T d);
		 T easeOutQuart(T t,T b , T c, T d);
		 T easeInOutQuart(T t,T b , T c, T d);
	
		 T easeInExpo(T t,T b , T c, T d);
		 T easeOutExpo(T t,T b , T c, T d);
		 T easeInOutExpo(T t,T b , T c, T d);
		 
		 T easeInElastic(T t,T b , T c, T d);
		 T easeOutElastic(T t,T b , T c, T d);
		 T easeInOutElastic(T t,T b , T c, T d);
					 
		 T easeInBounce(T t,T b , T c, T d);
		 T easeOutBounce(T t,T b , T c, T d);
		 T easeInOutBounce(T t,T b , T c, T d);
		 
};			 

#endif