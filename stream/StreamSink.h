/*
 * StreamSink.h
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
 *  Created on: Oct 10, 2013
 *      Author: emo
 */

#ifndef STREAMSINK_H_
#define STREAMSINK_H_

class Buffer;
class Stream;
class Stream;
class IStreamPacket;

class StreamSink
{
public:

    /**
    * Write data to sink.
    * @param packet - IStreamPacket holding the data and additional information.
    */
    virtual void WriteData(IStreamPacket& packet) = 0;

    /**
    * Start sink, before any operation could be performed sink must be started first.
    * @param s - Stream reference this sink is associated with.
    */
    virtual void Start(Stream& s) = 0;
};

#endif /* STREAMSINK_H_ */
