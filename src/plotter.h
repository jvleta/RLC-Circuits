#pragma once

#include <vtkChartXY.h>
#include <vtkContextScene.h>
#include <vtkContextView.h>
#include <vtkFloatArray.h>
#include <vtkPen.h>
#include <vtkPlot.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkTable.h>
#include <vtkVersion.h>

#include <vector>

void makeplots(std::vector<double>& x, std::vector<double>& y) {
  // Create a table with some points in it
  vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();

  vtkSmartPointer<vtkFloatArray> arrX = vtkSmartPointer<vtkFloatArray>::New();
  arrX->SetName("Time (seconds)");
  table->AddColumn(arrX);

  vtkSmartPointer<vtkFloatArray> arrC = vtkSmartPointer<vtkFloatArray>::New();
  arrC->SetName("Cosine");
  table->AddColumn(arrC);

  // Fill in the table with some example values
  int numPoints = 69;
  float inc = 7.5 / (numPoints - 1);
  table->SetNumberOfRows(numPoints);
  for (int i = 0; i < numPoints; ++i) {
    table->SetValue(i, 0, x[i]);
    table->SetValue(i, 1, y[i]);
  }

  // Set up the view
  vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);

  // Add multiple line plots, setting the colors etc
  vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();
  view->GetScene()->AddItem(chart);
  vtkPlot* line = chart->AddPlot(vtkChart::LINE);
  line->SetInputData(table, 0, 1);
  line->SetColor(0, 255, 0, 255);
  line->SetWidth(5.0);

  // Start interactor
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();
}