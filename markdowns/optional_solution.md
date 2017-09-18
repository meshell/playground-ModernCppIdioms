# std::optional

## Possible solution

```C++
#include <functional>
#include <sstream>
#include <string>
#include <optional>
#include <cmath>

// symmetric difference quotient
std::optional<double> differentiate(std::function<double(double)> f, double h, double x)
{
    const auto result = (f(x + h) - f(x - h)) / (2 * h);
    if (std::isnan(result)) {
        return {};
    }
    return result;
}

std::string estimated_velocity(std::function<double(double)> distance, double time, double precision)
{
    auto velocity = differentiate(distance, precision, time);

    std::stringstream output;
    if (velocity) {
        output << "Estimated velocity after " << time << " seconds is " << velocity.value() << " m/s.";
    } else {
        output << "Estimation failed.";
    }
    return output.str();
}
```
