#pragma once

class ArenaObject;

int readGuardHealth(ArenaObject const* t_object);
bool isExactGuard(ArenaObject const* t_object);
int requireGuardHealth(ArenaObject const* t_objects);
int countGuardViews(ArenaObject const* const * t_objects, int t_count);
int countExactGuards(ArenaObject const* const* t_objects, int t_count);
