#ifndef SPHERE_H
#define SPHERE_H

#include <object.h>

class Sphere : public Object {
public:
    Sphere(const glm::vec3& center, float radius, std::shared_ptr<Material> m) :
        Object(std::move(m)), c_(center), r_(radius) {}

    bool intersect(const Ray& r, Hit& out) const override {
        // TODO (paso 2): intersección rayo-esfera.
        // Un punto P está en la esfera si |P - c|^2 = r^2. Al reemplazar P por
        // el rayo, P(t) = o + t d: queda una cuadrática a t^2 + b t + cc = 0
        // (cc y no c, para no confundir el término independiente con el centro).
        //   - Discriminante negativo: el rayo no toca la esfera.
        //   - De las dos raíces, quedarse con la más chica que sea mayor que
        //     EPSILON. Si el origen del rayo está adentro de la esfera, la
        //     primera raíz es negativa y la segunda es la intersección que se
        //     ve desde dentro de la esfera.
        //   - Si ninguna es mayor que EPSILON, la esfera está detrás.
        //   - Completar out como en Plane. La normal hacia afuera es
        //     (P - c) normalizada.

        //Bhaskara para calcular las raices de la interseccion
        const float a = glm::dot(r.d(), r.d());
        const float b = -2.0f * glm::dot(r.d(), (c_ - r.o()));
        const float cc = glm::dot((c_ - r.o()),(c_ - r.o())) - r_*r_;

        const float disc = b*b - (4.0f * a * cc);

        // Rayo que no interseca la esfera (raices complejas conjugadas)
        if( disc <= EPSILON){
            return false;
        }

        const float sqrt = glm::sqrt(disc);
        const float den = 2.0f * a;

        const float t0 = (-b - sqrt) / den;
        const float t1 = (-b + sqrt) / den;

        if(t0 < EPSILON){
            if(t1 < EPSILON){
                return false;
            }
            else{
                out.t = t1;
                out.p = r.at(t1);
                const glm::vec3 n = glm::normalize(out.p - c_);
                out.set_face(r,n);
                out.mat = mat_.get();

                return true;
            }
        }
        else{
            out.t = t0;
            out.p = r.at(t0);
            const glm::vec3 n = glm::normalize(out.p - c_);
            out.set_face(r,n);
            out.mat = mat_.get();

            return true;
        }
    
    }

private:
    glm::vec3 c_;
    float r_;
};

#endif // SPHERE_H
