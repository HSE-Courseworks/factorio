#pragma once

#ifndef _OPT_H
#define _OPT_H

#include <optional>

void SetCurPos(int y, int x);

void ShowIcon(int y, int x, std::optional<Cell**> cells);

#endif //_OPT_H