#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds {
	class Line : public LblShape{
		int m_length{};
	public:
		Line();
		Line(const char * label, int length);
		~Line() = default;
		void getSpecs(std::istream& is) override;
		void draw(std::ostream& os) const override;
	};
}
#endif
