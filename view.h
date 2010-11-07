#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class SceneSettings;

class View : public QGraphicsView
{
    qreal current_zoom;

    Q_OBJECT
public:
    // has ownership of the scene
    explicit View(QGraphicsScene *scene = 0);
    virtual ~View();

    // destroys the old scene!
    void setScene(QGraphicsScene *scene);

signals:

public slots:
    void setOpenGL(bool enabled);
    void setAntialiasing(bool enabled);
    void setZoom(qreal zoom);
};

#endif // VIEW_H
