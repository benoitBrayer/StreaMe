#ifndef SOURCE_H
#define SOURCE_H
#include "project.h"
class Project;
class Source
{
public:
    Source(Project * project);
private:
    Project * project;
};

#endif // SOURCE_H
