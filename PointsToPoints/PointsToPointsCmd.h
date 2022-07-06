#ifndef _PointsToPointsCmd
#define _PointsToPointsCmd
//
// Copyright (C) zhaojiahua
// 
// File: PointsToPointsCmd.h
//
// MEL Command: PointsToPoints
//
// Author: Maya Plug-in Wizard 2.0
//

#include <maya/MPxCommand.h>
#include "maya/MSelectionList.h"
#include "maya/MFloatPointArray.h"
#include "maya/MDagPath.h"

class MArgList;

class PointsToPoints : public MPxCommand
{

public:
				PointsToPoints();
	virtual		~PointsToPoints();

	MStatus		doIt( const MArgList& );
	MStatus		redoIt();
	MStatus		undoIt();
	bool		isUndoable() const;

	static		void* creator();

private:
	// Store the data you will need to undo the command here
	//
	MSelectionList selectionlist;
	MFloatPointArray orgPoints;
	MDagPath path1, path2;
};

#endif
