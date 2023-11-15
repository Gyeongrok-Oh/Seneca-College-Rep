#include "Shape.h"

using namespace std;

namespace sdds {

	void Shape::draw(std::ostream& os) const {}

	void Shape::getSpecs(std::istream& is) {}

	std::ostream& operator<<(std::ostream& os, const Shape& shape)
	{
		shape.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Shape& shape)
	{
		shape.getSpecs(is);
		return is;
	}
}