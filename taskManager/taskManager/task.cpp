#include "task.h"

bool task::operator ==(const task& t)
{
	if (pId == t.pId)
		if (description == t.description)
			if (status == t.status)
				return true;
	return false;
}