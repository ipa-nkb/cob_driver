/****************************************************************
 *
 * Copyright (c) 2010
 *
 * Fraunhofer Institute for Manufacturing Engineering	
 * and Automation (IPA)
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Project name: care-o-bot
 * ROS stack name: cob_driver
 * ROS package name: cob_light
 * Description: Switch robots led color by sending data to
 * the led-µC over serial connection.
 *								
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *			
 * Author: Benjamin Maidel, email:benjamin.maidel@ipa.fraunhofer.de
 * Supervised by: Benjamin Maidel, email:benjamin.maidel@ipa.fraunhofer.de
 *
 * Date of creation: August 2012
 * ToDo:
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Fraunhofer Institute for Manufacturing 
 *       Engineering and Automation (IPA) nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as 
 * published by the Free Software Foundation, either version 3 of the 
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License LGPL for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public 
 * License LGPL along with this program. 
 * If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************/

#ifndef MODE_H
#define MODE_H

#include <colorUtils.h>
#include <boost/signals2.hpp>

class Mode
{
public:
	Mode(int priority = 0, double freq = 0, int pulses = 0, double timeout = 0)
		: _priority(priority), _freq(freq), _pulses(pulses), _timeout(timeout),
		  _finished(false), _pulsed(0){}
	virtual ~Mode(){}

	virtual void execute() = 0;

	virtual std::string getName() = 0;

	bool finished(){ return _finished; }

	void setPriority(int priority){ _priority = priority; }
	int getPriority(){ return _priority; }

	void setTimeout(int timeout){ _timeout = timeout; }
	double getTimeout(){ return _timeout; }

	void setFrequency(double freq){ _freq = freq; }
	double getFrequency(){ return _freq; }

	void setPulses(int pulses){ _pulses = pulses; }
	int getPulses(){ return _pulses; }

	int pulsed(){ return _pulsed; }

	void setColor(color::rgba color){ _color = color; }
	color::rgba getColor(){ return _color; }

	boost::signals2::signal<void (color::rgba color)>* signalColorReady(){ return &m_sigColorReady; }

protected:
	int _priority;
	double _freq;
	int _pulses;
	double _timeout;
	
	bool _finished;
	int _pulsed;

	color::rgba _color;

	boost::signals2::signal<void (color::rgba color)> m_sigColorReady;
};

#endif