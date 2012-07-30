/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __SPACE_HPP__
#define __SPACE_HPP__

// common include
#include "entity.hpp"	
#include "helper/debug_helper.hpp"
#include "cstdkbe/cstdkbe.hpp"
// #define NDEBUG
// windows include	
#if KBE_PLATFORM == PLATFORM_WIN32
#else
// linux include
#endif

namespace KBEngine{

class Space
{
public:
	Space(SPACE_ID spaceID, int32 mapSize = 0);
	~Space();

	void loadSpaceGeometry(const char* path);

	/** 更新space中的内容 */
	void update();

	void addEntity(Entity* pEntity);
protected:
	SPACE_ID id_;										// 这个space的ID
	std::map<ENTITY_ID, Entity*> entities_;				// 这个space上的entity
	bool isLoadGeometry_;								// 是否加载过地形数据
	int32 mapSize_;										// 地图大小
	std::string loadGeometryPathName_;					// 加载几何的路径
};


}
#endif
