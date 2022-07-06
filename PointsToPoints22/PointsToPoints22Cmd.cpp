//
// Copyright (C) zhaojiahua
// 
// File: PointsToPoints22Cmd.cpp
//
// MEL Command: PointsToPoints22
//
// Author: Maya Plug-in Wizard 2.0
//

#include "PointsToPoints22Cmd.h"
#include "maya/MFnMesh.h"
#include <maya/MGlobal.h>

MStatus PointsToPoints22::doIt(const MArgList&)
{
	MStatus stat = MS::kSuccess;
	return redoIt();
}

MStatus PointsToPoints22::redoIt()
{
	setResult("PointsToPoints22 command executed!\n");
	MGlobal::getActiveSelectionList(selectionlist, true);
	selectionlist.getDagPath(0, path1, MObject::kNullObj);
	selectionlist.getDagPath(1, path2, MObject::kNullObj);
	MFnMesh fnmesh1(path1);
	MFnMesh fnmesh2(path2);
	MFloatPointArray targetPoints;
	fnmesh1.getPoints(targetPoints);
	fnmesh2.getPoints(orgPoints);
	fnmesh2.setPoints(targetPoints);

	return MS::kSuccess;
}

MStatus PointsToPoints22::undoIt()
{

	MGlobal::displayInfo("PointsToPoints22 command undone!\n");
	MFnMesh fnmesh2(path2);
	fnmesh2.setPoints(orgPoints);
	return MS::kSuccess;
}

void* PointsToPoints22::creator()
{
	return new PointsToPoints22();
}

PointsToPoints22::PointsToPoints22()
{
	selectionlist = MSelectionList();
	orgPoints = MFloatPointArray();
	path1 = MDagPath();
	path2 = MDagPath();
}

PointsToPoints22::~PointsToPoints22() {}

bool PointsToPoints22::isUndoable() const { return true; }