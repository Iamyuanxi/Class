package com.SaleManage;

import com.SaleManage.Services.SalesmanService;
import com.SaleManage.Services.SalesmanServiceImpl;

import javax.swing.*;
import java.awt.*;

public class SalesmanManageWindow extends ManageWindow{
    SalesmanWindowTable windowTable = new SalesmanWindowTable();
    SalesmanManageWindowHandler salesmanManageWindowHandler;

    public SalesmanManageWindow(String title) {
        super(title);
        salesmanManageWindowHandler = new SalesmanManageWindowHandler(this);
        Container contentPane = super.getContentPane();

        layoutNorth(contentPane);
        layoutCenter(contentPane);
    }

    private void layoutCenter(Container contentPane) {
        TableDTO dto = getTableDTO();
        SalesmanWindowTableModel salesmanWindowTableModel = SalesmanWindowTableModel.assembleModel(dto.getData());
        //把jTable和model关联
        windowTable.setModel(salesmanWindowTableModel);
        windowTable.renderRule();

        JScrollPane jScrollPane = new JScrollPane(windowTable);

        contentPane.add(jScrollPane,BorderLayout.CENTER);
    }

    private void layoutNorth(Container contentPane) {
        //增加事件监听
        addButton.addActionListener(salesmanManageWindowHandler);
        updateButton.addActionListener(salesmanManageWindowHandler);
        deleteButton.addActionListener(salesmanManageWindowHandler);
        searchButton.addActionListener(salesmanManageWindowHandler);

        northPanel.add(addButton);
        northPanel.add(updateButton);
        northPanel.add(deleteButton);
        northPanel.add(searchText);
        northPanel.add(searchButton);
        contentPane.add(northPanel, BorderLayout.NORTH);
    }

    private TableDTO getTableDTO() {
        SalesmanService salesmanService = new SalesmanServiceImpl();
        Request request = new Request();

        request.setSearchKey(searchText.getText().trim());

        TableDTO tableDTO = salesmanService.retrieveSalesmans(request);

        return tableDTO;
    }

    public void reloadTable() {
        TableDTO dto = getTableDTO();

        SalesmanWindowTableModel.updateModel(dto.getData());

        windowTable.renderRule();
    }

    public String[] getSelectedSalesmanNumbers() {
        int[] selectedRows = windowTable.getSelectedRows();
        String[] numbers = new String[selectedRows.length];

        for (int i=0; i< selectedRows.length; ++i) {
            int rowIndex = selectedRows[i];
            Object nameObj = windowTable.getValueAt(rowIndex, 0);
            numbers[i] = nameObj.toString();
        }

        return numbers;
    }
}
