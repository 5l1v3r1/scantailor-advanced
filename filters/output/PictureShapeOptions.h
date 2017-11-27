//
// Created by Alex on 11/25/2017.
//

#ifndef SCANTAILOR_PICTURESHAPEOPTIONS_H
#define SCANTAILOR_PICTURESHAPEOPTIONS_H

class QString;
class QDomDocument;
class QDomElement;

namespace output {
    enum PictureShape {
        FREE_SHAPE,
        RECTANGULAR_SHAPE
    };
    
    class PictureShapeOptions {
    public:
        PictureShapeOptions();

        explicit PictureShapeOptions(QDomElement const& el);

        QDomElement toXml(QDomDocument& doc, QString const& name) const;

        bool operator==(PictureShapeOptions const& other) const;

        bool operator!=(PictureShapeOptions const& other) const;

        PictureShape getPictureShape() const;

        void setPictureShape(PictureShape pictureShape);

        int getSensitivity() const;

        void setSensitivity(int sensitivity);

        bool isAutoZonesFound() const;

        void setAutoZonesFound(bool autoZonesFound);

    private:
        static PictureShape parsePictureShape(const QString& str);

        static QString formatPictureShape(PictureShape type);

        PictureShape pictureShape;
        int sensitivity;
        
        bool autoZonesFound;
    };
}

#endif //SCANTAILOR_PICTURESHAPEOPTIONS_H