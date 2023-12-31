#import "MLNAnnotationController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An `MLNPolygonAnnotationController` is a controller that creates internally
 instances of an `MLNShapeSource` and `MLNFillStyleLayer` to simplify the creation
 of runtime styling based annotations to the map.
 
 Create instances of `MLNPolygonStyleAnnotation` and pass it to this controller.
 
 ### Example
 
 ```swift
 func mapView(_ mapView: MLNMapView, didFinishLoading style: MLNStyle) {
    let polygonAnnotationController = MLNPolygonAnnotationController(mapView: self.mapView)
 
    let polygonCoordinates = [
        CLLocationCoordinate2DMake(59, 18),
        CLLocationCoordinate2DMake(62, 19),
        CLLocationCoordinate2DMake(54, 20),
        CLLocationCoordinate2DMake(59, 18)
    ]
 
    let polygon = MLNPolygonStyleAnnotation(coordinates: polygonCoordinates, count: UInt(polygonCoordinates.count))
    polygon.fillOutlineColor = .red
    polygonAnnotationController.add(polygon)
 }
 ```
 */
@interface MLNPolygonAnnotationController : MLNAnnotationController

/**
 Determines whether of not the polygon style annotation should be [antialiased](https://en.wikipedia.org/wiki/Spatial_anti-aliasing).
 Defaults to `true`.
 
 This property corresponds to the `fill-antialias` property in the style [Mapbox Style Specification](https://docs.mapbox.com/mapbox-gl-js/style-spec/#paint-fill-fill-antialias).
 */
@property (nonatomic, assign) BOOL fillAntialiased;

/**
 The offset distance of the polygon style annotation from its anchor, measured in screen points. 
 Positive values indicate right and down, while negative values indicate left and up. 
 Defaults to a `CGVector` struct set to 0 points rightward and 0 points downward.
 
 This property corresponds to the `fill-translate` property in the style [Mapbox Style Specification](https://docs.mapbox.com/mapbox-gl-js/style-spec/#paint-fill-fill-translate).
 */
@property (nonatomic, assign) CGVector fillTranslation;

/**
 Controls the frame of reference for `fillTranslation`, as defined by `MLNFillTranslationAnchor`.
 Requires `fillTranslation`. Defaults to `map`.
 
 This property corresponds to the `line-cap` property in the style [Mapbox Style Specification](https://docs.mapbox.com/mapbox-gl-js/style-spec/#layout-line-line-cap).
 */
@property (nonatomic, assign) MLNFillTranslationAnchor fillTranslationAnchor;

@end

NS_ASSUME_NONNULL_END
