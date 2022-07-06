//
// Copyright (C) zhaojiahua
// 
// File: PointsToPointsCmd.cpp
//
// MEL Command: PointsToPoints
//
// Author: Maya Plug-in Wizard 2.0
//

#include "PointsToPointsCmd.h"
#include "maya/MFnMesh.h"
#include <maya/MGlobal.h>

MStatus PointsToPoints::doIt( const MArgList& )
{
	MStatus stat = MS::kSuccess;
	return redoIt();
}

MStatus PointsToPoints::redoIt()
{
	setResult( "PointsToPoints command executed!\n" );
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

MStatus PointsToPoints::undoIt()
{

    MGlobal::displayInfo( "PointsToPoints command undone!\n" );
	MFnMesh fnmesh2(path2);
	fnmesh2.setPoints(orgPoints);
	return MS::kSuccess;
}

void* PointsToPoints::creator()
{
	return new PointsToPoints();
}

PointsToPoints::PointsToPoints()
{
	selectionlist = MSelectionList();
	orgPoints = MFloatPointArray();
	path1 = MDagPath();
	path2 = MDagPath();
}

PointsToPoints::~PointsToPoints(){}

bool PointsToPoints::isUndoable() const { return true; }