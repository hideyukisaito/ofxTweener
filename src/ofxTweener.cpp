/*
 *  ofxTweener.cpp
 *  openFrameworks
 *
 *  Created by Sander ter Braak on 26-08-10.
 *
 *  Forked by Hideyuki Saito on 30-08-15
 *
 */

#include "ofxTweener.h"

template<typename T>
ofxTweener<T>::ofxTweener(){
	_scale = 1;
	setMode(TWEENMODE_OVERRIDE);
}

template<typename T>
void ofxTweener<T>::addTween(T &var, T to, T time, void (^callback)(T * arg))
{
    addTween(var, to, time, &ofxTransitions<T>::easeOutExpo, 0, 0, false, callback);
}

template<typename T>
void ofxTweener<T>::addTween(T &var, T to, T time, T (ofxTransitions<T>::*ease) (T,T,T,T), void (^callback)(T * arg))
{
    addTween(var, to, time, ease, 0, 0, false, callback);
}

template<typename T>
void ofxTweener<T>::addTween(T &var, T to, T time, T (ofxTransitions<T>::*ease) (T,T,T,T), T delay, void (^callback)(T * arg))
{
    addTween(var, to, time, ease, delay, 0, false, callback);
}

template<typename T>
void ofxTweener<T>::addTween(T &var, T to, T time, T (ofxTransitions<T>::*ease) (T,T,T,T), T delay, T bezierPoint, void (^callback)(T * arg))
{
    addTween(var, to, time, ease, delay, bezierPoint, true, callback);
}

template<typename T>
void ofxTweener<T>::addTween(T &var, T to, T time, T (ofxTransitions<T>::*ease) (T,T,T,T), T delay, T bezierPoint, bool useBezier, void (^callback)(T * arg))
{
    T from = var;
    T _delay = delay;
    Poco::Timestamp latest = 0;
    
    for(size_t i = 0; i < tweens.size(); ++i){
        if(tweens[i]._var == &var) {
            // object already tweening, just kill the old one
            if(_override){
                tweens[i]._from = from;
                tweens[i]._to = to;
                tweens[i]._by = bezierPoint;
                tweens[i]._useBezier = useBezier;
                tweens[i]._easeFunction = ease;
                tweens[i]._timestamp = Poco::Timestamp() + ((delay / _scale) * 1000000.0f) ;
                tweens[i]._duration = (time / _scale) * 1000000.0f;
                return;
            }
            else {
                //sequence mode
                if((tweens[i]._timestamp + tweens[i]._duration) > latest){
                    latest = (tweens[i]._timestamp + tweens[i]._duration);
                    delay = _delay + ((tweens[i]._duration - tweens[i]._timestamp.elapsed())/1000000.0f);
                    from = tweens[i]._to;
                }
            }
        }
    }
    
    Tween<T> t;
    
    t._var = &var;
    t._from = from;
    t._to = to;
    t._by = bezierPoint;
    t._useBezier = useBezier;
    t._easeFunction = ease;
    t._timestamp = Poco::Timestamp() + ((delay / _scale) * 1000000.0f) ;
    t._duration = (time / _scale) * 1000000.0f;
    
    tweens.push_back(t);
    
    if (callback!=NULL) callbacks[t._var] = callback;
}

template<typename T>
void ofxTweener<T>::update(){
    for(int i = tweens.size() -1; i >= 0; --i){
        if(T(tweens[i]._timestamp.elapsed()) >= T(tweens[i]._duration)){
            //tween is done
            
            bool found = false;
            if(!_override){
                //if not found anymore, place on exact place
                for(size_t j = 0; j < tweens.size(); ++j){
                    if(tweens[j]._var == tweens[i]._var) {
                        found = true;
                        break;
                    }
                }
            }
            if(!found) tweens[i]._var[0] = tweens[i]._to;
            
            typename map<T *,void (^)(T * arg)>::iterator it = callbacks.find(tweens[i]._var);
            if(it != callbacks.end()) {
                it->second(tweens[i]._var);
                callbacks.erase(it);
            }
            tweens.erase(tweens.begin() + i);
            
        }
        else if(T(tweens[i]._timestamp.elapsed()) > 0){
            //smaller than 0 would be delayed
            if(tweens[i]._useBezier) tweens[i]._var[0] = bezier(tweens[i]._from, tweens[i]._to ,(a.*tweens[i]._easeFunction )(T(tweens[i]._timestamp.elapsed()), 0, 1, T(tweens[i]._duration)), tweens[i]._by);
            else tweens[i]._var[0] = (a.*tweens[i]._easeFunction )(T(tweens[i]._timestamp.elapsed()), tweens[i]._from, tweens[i]._to - tweens[i]._from, T(tweens[i]._duration));
        }
    }
}

template<typename T>
T ofxTweener<T>::bezier(T b, T e, T t, T p){
    return b + t*(2*(1-t)*(p-b) + t*(e - b));
}

template<typename T>
void ofxTweener<T>::removeAllTweens(){
    tweens.clear();
}

template<typename T>
void ofxTweener<T>::setMode(int mode){
    _override = (mode == TWEENMODE_OVERRIDE);
}

template<typename T>
size_t ofxTweener<T>::getTweenCount(){
    return size_t(tweens.size());
}

template<typename T>
void ofxTweener<T>::setTimeScale(T scale){
    _scale = scale;
}


template class ofxTweener<float>;
template class ofxTweener<double>;
