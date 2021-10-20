package com.SaleManage;

import javax.swing.table.DefaultTableModel;
import java.util.Vector;

public class ProductWindowTableModel extends DefaultTableModel {
    static Vector<String> columns = new Vector<>();
    static {
        columns.addElement("编码");
        columns.addElement("名称");
        columns.addElement("总数");
        columns.addElement("进价");
        columns.addElement("厂商");
        columns.addElement("入库时间");
    }

    private ProductWindowTableModel() {
        super(null,columns);
    }

    private static ProductWindowTableModel productWindowTableModel = new ProductWindowTableModel();

    public static ProductWindowTableModel assembleModel(Vector<Vector<Object>> data) {
        productWindowTableModel.setDataVector(data,columns);
        return productWindowTableModel;
    }

    public static void updateModel(Vector<Vector<Object>> data) {
        productWindowTableModel.setDataVector(data,columns);
    }

    public static Vector<String> getColumns() {
        return columns;
    }

    @Override
    public boolean isCellEditable(int row, int column) {
        return false;
    }
}
