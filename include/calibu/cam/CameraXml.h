/* 
   This file is part of the Calibu Project.
   https://robotics.gwu.edu/git/calibu

   Copyright (C) 2013 George Washington University,
                      Steven Lovegrove,

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#pragma once

#include <calibu/cam/CameraRig.h>
#include <sstream>

namespace calibu
{

const std::string NODE_RIG           = "rig";
const std::string NODE_CAMMODEL_POSE = "camera";
const std::string NODE_CAMMODEL      = "camera_model";
const std::string NODE_POSE          = "pose";

///////////////////////////////////////////////////////////////////////////////
template <class T> inline
void StrToVal( T& t, const std::string& sValue )
{
    std::istringstream iss( sValue );
    iss >> t;
}

///////////////////////////////////////////////////////////////////////////////
template <class T> inline
T StrToVal( const std::string& sValue, const T default_val = T() )
{
    T t = default_val;
    std::istringstream iss( sValue );
    iss >> t;
    return t;
}

///////////////////////////////////////////////////////////////////////////////
template <class T> inline
std::string ValToStr( const T& t )
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

///////////////////////////////////////////////////////////////////////////////
std::string CameraModelType( const std::string& sType );

///////////////////////////////////////////////////////////////////////////////

void WriteXmlCameraModel(std::ostream& out, const CameraModelInterface& cam, int indent = 0);
void WriteXmlCameraModel(const std::string& filename, const CameraModelInterface& cam);
//CameraModel ReadXmlCameraModel(TiXmlElement* pEl);
CameraModel ReadXmlCameraModel(const std::string& filename);

////////////////////////////////////////////////////////////////////////

void WriteXmlSE3(std::ostream& out, const Sophus::SE3d& T_wc, int indent = 0);
void WriteXmlSE3(const std::string& filename, const Sophus::SE3d& T_wc);
//Sophus::SE3d ReadXmlSE3(TiXmlNode* xmlcampose);
Sophus::SE3d ReadXmlSE3(const std::string& filename);

////////////////////////////////////////////////////////////////////////

void WriteXmlCameraModelAndPose(std::ostream& out, const CameraModelAndPose& cop, int indent = 0);
void WriteXmlCameraModelAndPose(const std::string& filename, const CameraModelAndPose& cop);
//CameraModelAndPose ReadXmlCameraModelAndPose(TiXmlNode* xmlcampose);
CameraModelAndPose ReadXmlCameraModelAndPose(const std::string& filename);

////////////////////////////////////////////////////////////////////////

void WriteXmlRig(std::ostream& out, const CameraRig& rig, int indent = 0);
void WriteXmlRig(const std::string& filename, const CameraRig& rig);
//CameraRig ReadXmlRig(TiXmlNode* xmlrig);
CameraRig ReadXmlRig(const std::string& filename);


}