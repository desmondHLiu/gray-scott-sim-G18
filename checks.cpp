#include <vector>
#include <boost/type_index.hpp>
#include <boost/assert.hpp>

void checkTypes(double F, double k, const std::vector<std::vector<double>>& u) {
    BOOST_ASSERT_MSG(boost::typeindex::type_id_with_cvr<decltype(F)>().pretty_name() == boost::typeindex::type_id_with_cvr<decltype(u[0][0])>().pretty_name(), "Type of F does not match type of elements in u and v");
    BOOST_ASSERT_MSG(boost::typeindex::type_id_with_cvr<decltype(k)>().pretty_name() == boost::typeindex::type_id_with_cvr<decltype(u[0][0])>().pretty_name(), "Type of k does not match type of elements in u and v");
}

void checkSizes(const std::vector<std::vector<double>>& u, const std::vector<std::vector<double>>& v) {
    BOOST_ASSERT_MSG(u.size() == v.size(), "u and v are not the same size");
}

void checkSimulation(const std::vector<std::vector<double>>& u, const std::vector<std::vector<double>>& v) {
    for (const auto& row : u) {
        for (const auto& element : row) {
            BOOST_ASSERT_MSG(abs(element - 0.0) < 1e-9, "Simulation does not produce correct result when u = 0");
        }
    }
    for (const auto& row : v) {
        for (const auto& element : row) {
            BOOST_ASSERT_MSG(abs(element - 0.0) < 1e-9, "Simulation does not produce correct result when v = 0");
        }
    }
}