#ifndef _PointsToPoints22Cmd
#define _PointsToPoints22Cmd
//
// Copyright (C) zhaojiahua
// 
// File: PointsToPoints22Cmd.h
//
// MEL Command: PointsToPoints22
//
// Author: Maya Plug-in Wizard 2.0
//

#include <maya/MPxCommand.h>
#include "maya/MSelectionList.h"
#include "maya/MFloatPointArray.h"
#include "maya/MDagPath.h"

class MArgList;

class PointsToPoints22 : public MPxCommand
{

public:
	PointsToPoints22();
	virtual		~PointsToPoints22();

	MStatus		doIt(const MArgList&);
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
