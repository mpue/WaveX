//
//  Singleton.h
//  WaveX
//
//  Created by Matthias Pueski on 29.12.16.
//
//

#ifndef Singleton_h
#define Singleton_h

template <typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }
    
    
protected:
    Singleton() {}
    ~Singleton() {}
public:
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;
};

#endif /* Singleton_h */
