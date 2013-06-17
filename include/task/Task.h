/*
 * Task.h
 *
 * Copyright (C) 2013  Emil Penchev, Bulgaria
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 *  Created on: May 31, 2013
 *      Author: emo
 */

#ifndef TASK_H_
#define TASK_H_

#include <boost/noncopyable.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "SystemThread.h"

/**
* Almost all operations are asynchronous and executed by a object of type Task.
*/

class Task : private boost::noncopyable
{
public:
    Task() {}
    virtual ~Task() {}

    /**
    * Template functions for connecting the task Run()
    * functor with object reference and member function.
    * Connect_1 -> member function with 1 parameter.
    * Connect_2 -> member function with 2 parameters.
    * Connect_3 -> member function with 3 parameters.
    */
    template <class Operation, class ObjectT, class T1>
    inline void Connect_1(Operation op, ObjectT* obj_ptr, T1 param_1)
    {
        Run = boost::bind(op, obj_ptr, param_1);
    }

    template <class Operation, class ObjectT, class T1>
    inline void Connect_1(Operation op, ObjectT& obj_ref, T1 param_1)
    {
        Run = boost::bind(op, obj_ref, param_1);
    }

    template <class Operation, class ObjectT, class T1, class T2>
    inline void Connect_2(Operation op, ObjectT* obj_ptr, T1 param_1, T2 param_2)
    {
        Run = boost::bind(op, obj_ptr, param_1, param_2);
    }

    template <class Operation, class ObjectT, class T1, class T2>
    inline void Connect_2(Operation op, ObjectT& obj_ref, T1 param_1, T2 param_2)
    {
        Run = boost::bind(op, obj_ref, param_1, param_2);
    }

    template <class Operation, class ObjectT, class T1, class T2, class T3>
    inline void Connect_3(Operation op, ObjectT* obj_ptr, T1 param_1, T2 param_2, T3 param_3)
    {
        Run = boost::bind(op, obj_ptr, param_1, param_2, param_3);
    }

    template <class Operation, class ObjectT, class T1, class T2, class T3>
    inline void Connect_3(Operation op, ObjectT& obj_ref, T1 param_1, T2 param_2, T3 param_3)
    {
        Run = boost::bind(op, obj_ref, param_1, param_2, param_3);
    }

    template <class T>
    inline T* GetPtrToObject() { return (T*)enclosedObject; }

    template <class T>
    inline T GetObject() { return *(T*)(enclosedObject); }

    void  AddObject(void* inObj) { enclosedObject = inObj; }

    boost::function<void()> Run; /**< boost functor object */

private:
    void* enclosedObject;

};

#endif /* TASK_H_ */