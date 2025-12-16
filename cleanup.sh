#!/bin/bash
find . -type f -name "*.o" -delete
find . -type f -name "*.log" -delete
find . -type d -name "__pycache__" -exec rm -rf {} +